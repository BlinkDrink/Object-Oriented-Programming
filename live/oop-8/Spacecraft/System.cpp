#include "System.h"

const int MAX_LEN = 128;

System::System()
{}

System& System::getInstance()
{
    static System sys;
    return sys;
}

void System::readInput(const string& file, spacecrafts& spacecrafts)
{
    ifstream in(file);
    if (!in)
    {
        throw std::invalid_argument("Couldn't open the file for reading!");
    }

    size_t year;
    string name;

    while (!in.eof())
    {
        in >> year;
        in.ignore();
        getline(in, name);
        spacecrafts.push_back({ year, name });
    }

    in.close();
}

void System::serialize(const string& file, spacecrafts& spacecrafts) const
{
    ofstream out(file, std::ios::binary);
    if (!out)
    {
        throw std::invalid_argument("Couldn't open file for writing!");
    }

    size_t size = spacecrafts.size();
    for (size_t i = 0; i < size; i++)
    {
        spacecrafts[i].serialize(out);
    }

    out.close();
}

void System::deserialize(const string& file, spacecrafts& spacecrafts)
{
    ifstream in(file, std::ios::binary);
    if (!in)
    {
        throw std::invalid_argument("Couldn't open file for reading!");
    }

    size_t size = spacecrafts.size();
    for (size_t i = 0; i < size; i++)
    {
        spacecrafts[i].deserialize(in);
    }

    in.close();
}

void System::run()
{
    string file;
    std::cout << "Enter file path: ";
    std::cin >> file;

    try
    {
        readInput(file, m_spacecrafts);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Enter binary file path: ";
    std::cin >> file;
    try
    {
        serialize(file, m_spacecrafts);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        deserialize(file, m_spacecrafts);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    size_t size = m_spacecrafts.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << m_spacecrafts[i] << '\t';
    }
}

System::~System()
{}