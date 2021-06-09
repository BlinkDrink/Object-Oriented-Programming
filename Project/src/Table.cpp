#include <cstring>
#include <string>
#include <cmath>
#include "../include/Table.h"
#include "../include/DoubleType.h"
#include "../include/IntegerType.h"
#include "../include/StringType.h"
#include "../include/FormulaType.h"
#include "../include/StringHelper.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;
using std::to_string;

Table::Table() : m_rows(0), m_cols(0) {}

size_t Table::getLongestContentAtCol(size_t col) const
{
    size_t longest = 0;
    StringHelper sh;

    for (size_t i = 0; i < m_rows; i++)
    {
        CellType *content = m_cells[i][col].getContent();
        if (content != nullptr)
        {
            // if (content->getDataType() == DataType::FORMULA)
            // {
            //     size_t calcSize = sh.calculateEquationInString(content->toString()).size();
            //     if (longest < calcSize)
            //         longest = calcSize;
            // }
            // else
            // {
            if (longest < content->size())
                longest = content->size();
        }
    }

    return longest;
}

vector<size_t> Table::getLongestWordPerCol() const
{
    vector<size_t> lengthPerCol;

    for (size_t i = 0; i < m_cols; i++)
    {
        lengthPerCol.push_back(getLongestContentAtCol(i));
    }

    return lengthPerCol;
}

Table::Table(size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        vector<Cell> newRow;
        for (size_t j = 0; j < cols; j++)
        {
            newRow.push_back(Cell("", *this));
        }
        m_cells.push_back(newRow);
    }

    m_rows = rows;
    m_cols = cols;
}

void Table::print() const
{
    if (empty())
    {
        cout << "Table is empty." << endl;
        return;
    }

    printFirstRow();
    printAfterFirstRow();
}

void Table::setCellAt(size_t row, size_t col, const Cell &cell)
{
    if (col >= 26)
    {
        throw invalid_argument("Columns cannot exceed 25(counting from 0)");
    }

    if (row + 1 > m_rows)
    {
        expandRows(row + 1);
    }

    if (col + 1 > m_cols)
    {
        expandCols(col + 1);
    }

    m_cells[row][col] = cell;
}

void Table::expandRows(size_t row)
{
    size_t rowsToAdd = row - m_rows;
    for (size_t i = 0; i < rowsToAdd; i++)
    {
        vector<Cell> newRow;
        for (size_t i = 0; i < m_cols; i++)
        {
            newRow.push_back(Cell(nullptr));
        }
        m_cells.push_back(newRow);
        m_rows++;
    }
}

void Table::expandCols(size_t col)
{
    for (size_t i = 0; i < m_rows; i++)
    {
        while (m_cells[i].size() != col)
        {
            m_cells[i].push_back(Cell(nullptr));
        }
    }

    m_cols = col;
}

const vector<Cell> &Table::operator[](size_t row) const
{
    return m_cells[row];
}

size_t Table::getRows() const { return m_rows; }

size_t Table::getCols() const { return m_cols; }

bool Table::empty() const
{
    if (m_rows == 0 && m_cols == 0)
        return true;

    return false;
}

void Table::printFirstRow() const
{
    vector<size_t> longestWordsPerCol = getLongestWordPerCol();

    StringHelper sh;
    size_t rowsLen = m_rows == 0 ? 0 : log10(m_rows) + 1;
    string leadingSpace = sh.getStringFilledWithSpaces(rowsLen);
    cout << leadingSpace;
    for (size_t i = 0; i < m_cols; i++)
    {
        string spaces;
        if (longestWordsPerCol[i] != 0)
        {
            spaces = sh.getStringFilledWithSpaces(longestWordsPerCol[i] - 1);
        }
        else
        {
            spaces = sh.getStringFilledWithSpaces(longestWordsPerCol[i]);
        }
        cout << " | " << (char)(i + 65) << spaces;
    }

    cout << " |" << endl;
}

void Table::printAfterFirstRow() const
{
    vector<size_t> longestWordsPerCol = getLongestWordPerCol();
    StringHelper sh;
    size_t rowsLen = m_rows == 0 ? 0 : log10(m_rows) + 1;

    for (size_t i = 0; i < m_rows; i++)
    {
        string spacesForNumbersCol = sh.getStringFilledWithSpaces(rowsLen - strlen(to_string(i + 1).c_str()));
        cout << i + 1 << spacesForNumbersCol << " | ";
        for (size_t j = 0; j < m_cols; j++)
        {
            printCellInformation(i, j, longestWordsPerCol[j]);
            cout << " | ";
        }
        cout << endl;
    }
}

void Table::printCellInformation(size_t row, size_t col, size_t longestWordOfCol) const
{
    StringHelper sh;
    CellType *content = m_cells[row][col].getContent();
    if (content != nullptr)
    {
        string spaces;
        // if (content->getDataType() == DataType::FORMULA)
        // {
        //     size_t sizeOfCalc = sh.calculateEquationInString(content->toString()).size();
        //     spaces = sh.getStringFilledWithSpaces(longestWordOfCol - sizeOfCalc);
        // }
        //else
        //{
        spaces = sh.getStringFilledWithSpaces(longestWordOfCol - content->size());

        content->print();
        cout << spaces;
    }
    else
    {
        string spaces;
        if (longestWordOfCol == 0)
            spaces = sh.getStringFilledWithSpaces(longestWordOfCol + 1);
        else
            spaces = sh.getStringFilledWithSpaces(longestWordOfCol);

        cout << spaces;
    }
}

void Table::clearTable()
{
    for (size_t i = 0; i < m_cells.size(); i++)
    {
        for (size_t j = 0; j < m_cells[i].size(); j++)
        {
            m_cells[i].clear();
        }
    }

    m_cells.clear();
    m_cols = 0;
    m_rows = 0;
}
