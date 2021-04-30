#include "Garage.h"
#include "termcolor.hpp" //using an open-source library to color the text output on the console

using std::cout;
using std::cin;

void menu() {
	cout << "\n\n\t\tMENU\n";
	cout << "\t1. Add vehicle\n";
	cout << "\t2. Remove vehicle\n";
	cout << "\t3. List all vehicles\n";
	cout << "\t4. Clear console\n";
	cout << "\t0. Exit\n";
	cout << "\tEnter command: ";
}

void addVehicle(Garage& g, Vehicle** vehicles, unsigned& vIndex) {
	cin.ignore();
	MyString reg;
	MyString des;
	size_t space;

	char buffer[200];

	cout << termcolor::underline << "\nEnter vehicle registration number: " << termcolor::reset;
	cin.getline(buffer, 200);
	reg = buffer;

	cout << termcolor::underline << "\nEnter vehicle description: " << termcolor::reset;
	cin.getline(buffer, 200);
	des = buffer;

	cout << termcolor::underline << "\nEnter parking spaces that the vehicle occupies: " << termcolor::reset;
	cin >> space;

	Vehicle* v = nullptr;

	try
	{
		v = new Vehicle(reg.c_str(), des.c_str(), space);
	}
	catch (const std::invalid_argument& e)
	{
		cout << '\n' << termcolor::red << e.what() << termcolor::reset;
		return;
	}

	try
	{
		g.insert(*v);
	}
	catch (const std::out_of_range& e)
	{
		delete v;
		cout << '\n' << termcolor::red << e.what() << termcolor::reset;
		return;
	}
	catch (const std::invalid_argument& e)
	{
		delete v;
		cout << '\n' << termcolor::red << e.what() << termcolor::reset;
		return;
	}

	vehicles[vIndex++] = v;
	cout << termcolor::green << "Successfully added vehicle with registration " << v->registration() << termcolor::reset;
}

void removeVehicle(Garage& g) {
	cin.ignore();
	MyString reg;
	char buffer[100];
	cout << termcolor::underline << "\nEnter the registration of the vehicle that you want removed: " << termcolor::reset;
	cin.getline(buffer, 100);
	reg = buffer;


	if (g.find(reg.c_str()) == nullptr)
	{
		cout << termcolor::red << "\nNot found!" << termcolor::reset;
	}
	else
	{
		try
		{
			g.erase(reg.c_str());
		}
		catch (const std::invalid_argument& e)
		{
			cout << termcolor::red << e.what() << termcolor::reset << '\n';
		}
		cout << termcolor::green << "Successfully removed vehicle with registration " << reg.c_str() << termcolor::reset;
	}
}

void printGarage(Garage& g) {
	if (!g.empty()) {
		cout << termcolor::yellow
			<< "======================================";

		for (size_t i = 0; i < g.size(); i++)
		{
			cout << "\nVehicle #" << i + 1;
			cout << "\n\tRegistration number: " << g.at(i).registration();
			cout << "\n\tDescription: " << g.at(i).description();
			cout << "\n\tSpaces taken: " << g.at(i).space();
			cout << '\n';
		}

		cout << "======================================" << termcolor::reset;
	}
	else
	{
		cout << termcolor::green << "Garage is empty." << termcolor::reset;
	}
}

int main() {
	size_t capacity;
	size_t cmd;
	cout << "Enter the capacity of the garage: ";

	do
	{
		cin >> capacity;
		if (capacity == 0)
		{
			cout << "Garage cannot have 0 capacity. Enter capacity again: ";
		}
	} while (capacity == 0);

	Garage g1(capacity);

	Vehicle** vehicles = new Vehicle * [capacity];
	unsigned vehiclesIndex = 0;

	do
	{
		menu();
		cin >> cmd;

		switch (cmd)
		{
		case 1:
			addVehicle(g1, vehicles, vehiclesIndex);
			break;
		case 2:
			removeVehicle(g1);
			break;
		case 3:
			printGarage(g1);
			break;
		case 4:
			system("cls");
			break;
		case 0:
			break;
		default:
			cout << termcolor::red << "Invalid command!" << termcolor::reset;
			break;
		}
	} while (cmd != 0);

	for (size_t i = 0; i < vehiclesIndex; i++)
	{
		delete vehicles[i];
	}

	delete[] vehicles;

	return 0;
}