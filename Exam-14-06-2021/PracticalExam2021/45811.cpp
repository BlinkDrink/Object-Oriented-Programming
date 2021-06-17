// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Практически изпит
// 
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Ден, в който се явявате на изпита: 14.06.2021 
// Начален час на изпита: 9:00
// Кой компилатор използвате: Visual C++
//
#define _CRT_SECURE_NO_WARNINGS 

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::ostream;
using std::ofstream;
using std::invalid_argument;
using std::out_of_range;
using std::bad_alloc;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

const double PRICE_PER_CORE = 29.99;
const double PRICE_PER_GB = 89.99;
const unsigned short NUMBER_OF_COMPONENT_TYPES = 2;

class component {
protected:
	const string m_label;

public:
	component(const string& label) : m_label(label) {}

	virtual double price() const = 0;
	virtual void output(ostream& out) const = 0;
	virtual ~component() = default;
};

class cpu : public component {
private:
	const unsigned short m_cores;
	const unsigned short m_clock_speed;

public:
	cpu(const string& label, unsigned short cores, unsigned short clockSpeed)
		: component(label), m_cores(cores), m_clock_speed(clockSpeed) {
		if (m_cores < 1 || m_cores > 8)
		{
			throw invalid_argument("Number of cores can be between 1 and 8");
		}
	}

	virtual double price() const override {
		return m_cores * PRICE_PER_CORE;
	}

	virtual void output(ostream& out) const override {
		out << m_label << " " << price() << endl;
	}
};

class memory : public component {
private:
	const unsigned short m_capacity;

public:
	memory(const string& label, unsigned short capacity)
		: component(label), m_capacity(capacity)
	{
		if (capacity < 1 || capacity > 1000000)
		{
			throw invalid_argument("Capacity can be a number between 1 and 1 000 000");
		}
	}

	virtual double price() const override {
		return m_capacity * PRICE_PER_GB;
	}

	virtual void output(ostream& out) const override {
		out << m_label << " " << price() << endl;
	}
};

component* create_component() {
	component* comp = nullptr;

	char choice;
	cout << "Choose a component to create, either cpu or memory (c/m): ";
	cin >> choice;
	cin.ignore();

	string label;
	switch (choice)
	{
	case 'c':
		unsigned short cores, clock_speed;
		cout << "Enter label of item: ";
		getline(cin, label);
		cout << "Enter number of cores: ";
		cin >> cores;
		cout << "Enter clock speed: ";
		cin >> clock_speed;

		try
		{
			comp = new cpu(label, cores, clock_speed);
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			comp = nullptr;
		}

		break;
	case 'm':
		unsigned short capacity;
		cout << "Enter label of item: ";
		getline(cin, label);
		cout << "Enter number for capacity: ";
		cin >> capacity;

		try
		{
			comp = new memory(label, capacity);
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			comp = nullptr;
		}

		break;
	default:
		cout << "Invalid choice\n";
		break;
	}

	return comp;
}

class configuration {
private:
	vector<const component*> m_components;

	/**
	 * @brief Checks if the given component's type exists in the list
	 * @param c	component to check if contained
	 * @return true if contained, false otherwise
	*/
	bool containsComponent(const component* c) {
		for (size_t i = 0; i < m_components.size(); i++)
		{
			if (typeid(*m_components[i]) == typeid(*c))
				return true;
		}

		return false;
	}

	void insert(const component* c) {
		if (containsComponent(c))
		{
			throw invalid_argument("There is already a component of the same type");
		}

		m_components.push_back(c);
	}

	configuration() = default;
	configuration(const configuration& other) = default;
	configuration& operator=(const configuration& other) = default;
public:
	double price() const {
		double total_price = 0;
		for (size_t i = 0; i < m_components.size(); i++)
			total_price += m_components[i]->price();

		return total_price;
	}

	size_t size() const {
		return m_components.size();
	}

	const component& operator[](size_t pos) const {
		if (pos >= m_components.size() - 1)
		{
			throw out_of_range("Index out of bounds");
		}

		return *m_components[pos];
	}

	friend const configuration& operator<<(ostream& out, const configuration& config) {
		for (size_t i = 0; i < config.m_components.size(); i++)
		{
			config.m_components[i]->output(out);
		}

		out << config.price() << endl;

		return config;
	}

	friend configuration* create_configuration();

	void clearConfig() {
		for (size_t i = 0; i < m_components.size(); i++)
		{
			delete m_components[i];
		}
	}

	~configuration() {
		clearConfig();
	}
};

configuration* create_configuration() {
	configuration* config = nullptr;

	try
	{
		config = new configuration;
	}
	catch (const bad_alloc& e)
	{
		cout << e.what() << endl;
		return nullptr;
	}

	unsigned short components_to_input;
	cout << "Enter number of components you wish to input: ";
	cin >> components_to_input;

	for (size_t i = 0; i < components_to_input; i++)
	{
		if (config->m_components.size() == NUMBER_OF_COMPONENT_TYPES)
		{
			break;
		}

		try
		{
			component* comp = create_component();

			if (comp != nullptr)
			{
				config->insert(comp);
			}
		}
		catch (const invalid_argument& e)
		{
			cout << e.what() << endl;
			i--;
		}
	}

	return config;
}

int main()
{
	configuration* config = create_configuration();
	cout << *config;
	cin.ignore();

	string path;
	cout << "Enter path to file: ";
	getline(cin, path);

	ofstream out(path);
	out << *config;

	delete config;
	return 0;
}