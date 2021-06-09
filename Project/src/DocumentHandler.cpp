#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/termcolor.hpp"
#include "../include/DocumentHandler.h"
#include "../include/StringHelper.h"
#include "../include/CommandParser.h"
#include "../include/IntegerType.h"
#include "../include/DoubleType.h"
#include "../include/FormulaType.h"
#include "../include/StringType.h"

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::invalid_argument;
using std::out_of_range;
using std::string;
using std::to_string;
using termcolor::green;
using termcolor::red;
using termcolor::reset;
using termcolor::yellow;

DocumentHandler::DocumentHandler()
{
}

void DocumentHandler::menu() const
{
}

DocumentHandler &DocumentHandler::getInstance()
{
    static DocumentHandler inst;
    return inst;
}

void DocumentHandler::populateTableFromFile()
{
    initializeEmptyTableFromFile();

    if (!m_reader.good())
        m_reader.clear();

    m_reader.seekg(0, std::ios_base::beg);

    fillTableFromFile();
}

bool DocumentHandler::openFile(const string &path)
{
    if (isDocumentLinkedToFile())
    {
        if (!closeFile())
            return false;
    }

    m_reader.open(path);

    if (!m_reader.is_open())
    {
        throw invalid_argument("Couldn't open file for reading.");
    }

    clearState(false, false, true, false);
    populateTableFromFile();

    m_reader.close();
    m_writer.open(path);

    if (!isDocumentLinkedToFile())
    {
        throw invalid_argument("Couldn't link current document with the file.");
    }

    m_filePath = path;
    clearState(false, true);
    return true;
}

bool DocumentHandler::closeFile()
{
    if (!isDocumentLinkedToFile())
        throw invalid_argument("Cannot close - no document loaded");

    if (!m_isSaved)
    {
        while (true)
        {
            char choice;
            cout << "There are unsaved changes. SAVE/DON'T SAVE/CANCEL(s/d/c): ";
            cin >> choice;
            if (choice == 's')
            {
                saveToFile();
                m_writer.close();
                cout << green << "File saved." << reset << endl;
                break;
            }
            else if (choice == 'd')
            {
                m_writer.close();
                cout << yellow << "File not saved." << reset << endl;
                break;
            }
            else if (choice == 'c')
            {
                cin.ignore();
                return false;
            }
            else
            {
                cout << red << "Invalid choice" << reset << endl;
            }
        }
        cin.ignore();
    }
    else
    {
        m_writer.close();
    }

    clearState(false, false, true, true);
    return true;
}

void DocumentHandler::saveToFile()
{
    if (!isDocumentLinkedToFile())
    {
        throw invalid_argument("Cannot save - no document loaded");
    }

    StringHelper sh;
    m_writer.close();
    m_writer.open(m_filePath);

    for (size_t i = 0; i < m_table.getRows(); i++)
    {
        for (size_t j = 0; j < m_table[i].size(); j++)
        {
            m_writer << m_table[i][j].getContent()->toFileFormat();

            if (j != m_table[i].size() - 1)
            {
                m_writer << ",";
            }
        }
        m_writer << endl;
    }

    setState(true);
}

void DocumentHandler::saveFileAs(const string &path)
{
    if (!isDocumentLinkedToFile() && !m_isNew)
    {
        throw invalid_argument("Cannot saveas - there is no loaded document or the document is not new");
    }

    if (isDocumentLinkedToFile())
    {
        m_writer.close();
    }

    m_writer.open(path);

    if (!isDocumentLinkedToFile())
    {
        throw invalid_argument("Couldn't open file.");
    }

    m_filePath = path;
    saveToFile();
    clearState(false, true);
}

bool DocumentHandler::createNewDocument()
{
    if (isDocumentLinkedToFile())
    {
        if (!closeFile())
            return false;
    }

    setState(false, true);
    clearState(false, false, true, true);

    return true;
}

void DocumentHandler::editFile(size_t row, size_t col, const string &content)
{
    if (!m_isNew && !isDocumentLinkedToFile())
    {
        throw invalid_argument("Cannot edit - no document loaded");
    }

    alterCell(row, col, content);
    clearState(true);
}

void DocumentHandler::alterCell(size_t row, size_t col, const string &content)
{
    StringHelper sh;
    string cpy(content);
    sh.trim(cpy);

    Cell c(content, m_table);

    m_table.setCellAt(row, col, c);
}

bool DocumentHandler::isDocumentLinkedToFile() const
{
    if (!m_writer.is_open())
    {
        return false;
    }

    return true;
}

void DocumentHandler::initializeEmptyTableFromFile()
{
    StringHelper sh;
    size_t rowsOfFile = 0;
    size_t maxColOfFile = 0;
    string content;

    while (getline(m_reader, content))
    {
        rowsOfFile++;
        vector<string> parts = sh.splitBy(content, ",");
        if (maxColOfFile < parts.size())
        {
            maxColOfFile = parts.size();
        }
    }

    m_table.expandRows(rowsOfFile);
    m_table.expandCols(maxColOfFile);
}

void DocumentHandler::fillTableFromFile()
{
    StringHelper sh;
    size_t currRow = 0;
    string content;

    while (getline(m_reader, content))
    {
        vector<string> parts = sh.splitBy(content, ",");
        for (size_t i = 0; i < parts.size(); i++)
        {
            alterCell(currRow, i, parts[i]);
        }
        currRow++;
    }
}

void DocumentHandler::run()
{
    menu();
    CommandParser cp;
    StringHelper sh;

    while (true)
    {
        string cmd, fileIndicator;
        if (m_isNew)
            fileIndicator = "new document";
        else if (!m_filePath.empty())
            fileIndicator = m_filePath;
        else
            fileIndicator = "no selected file";
        cout << "(" + fileIndicator + ")" + ">";

        getline(cin, cmd);

        cp.clearCmd();
        try
        {
            cp.setData(cmd);
        }
        catch (const invalid_argument &e)
        {
            cout << red << e.what() << reset << endl;
            continue;
        }

        switch (cp.getCommandType())
        {
        case CommandType::OPEN:
            try
            {
                if (!openFile(cp.atToken(1)))
                    break;
            }
            catch (const invalid_argument &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }
            catch (const out_of_range &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Successfully opened " << cp.atToken(1) << reset << endl;
            break;
        case CommandType::CLOSE:
            try
            {
                if (!closeFile())
                    break;
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Successfully closed file." << reset << endl;
            break;
        case CommandType::NEW:
            try
            {
                if (!createNewDocument())
                    break;
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Succesfully created new document" << reset << endl;
            break;
        case CommandType::SAVE:
            try
            {
                saveToFile();
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Successfully saved file into " << m_filePath << reset << endl;
            break;
        case CommandType::SAVEAS:
            try
            {
                saveFileAs(cp.atToken(1));
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Successfully saved table to " << m_filePath << reset << endl;
            break;
        case CommandType::EDIT:
            try
            {
                if (!sh.isStringValidCellAddress(cp.atToken(1)))
                {
                    cout << red << "Invalid formula address" << reset << endl;
                    break;
                }

                Pair<size_t, size_t> pair = sh.extractCellAddressDetails(cp.atToken(1));
                editFile(pair.key, pair.value, cp.atToken(2));
            }
            catch (const invalid_argument &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << green << "Successfully set cell " << cp.atToken(1) << ", with content " << cp.atToken(2) << reset << endl;
            break;
        case CommandType::PRINT:
            try
            {
                m_table.print();
            }
            catch (const std::exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            break;
        case CommandType::EXIT:
            try
            {
                if (isDocumentLinkedToFile())
                {
                    if (!closeFile())
                        break;
                }
            }
            catch (const exception &e)
            {
                cout << red << e.what() << reset << endl;
                break;
            }

            cout << termcolor::magenta << "Exiting the program..." << reset << endl;
            return;
        case CommandType::NOCOMMAND:
            cout << red << "Invalid command." << reset << endl;
            break;
        default:
            break;
        }
    }
}

void DocumentHandler::clearState(bool turn_off_saved, bool turn_off_new, bool clear_table, bool clear_filePath)
{
    if (clear_filePath)
        m_filePath.clear();

    if (clear_table)
        m_table.clearTable();

    if (turn_off_new)
        m_isNew = false;

    if (turn_off_saved)
        m_isSaved = false;
}

void DocumentHandler::setState(bool turn_on_saved, bool turn_on_new)
{
    if (turn_on_new)
        m_isNew = true;

    if (turn_on_saved)
        m_isSaved = true;
}

DocumentHandler::~DocumentHandler()
{
    if (m_reader.is_open())
        m_reader.close();

    if (m_writer.is_open())
        m_writer.close();
}