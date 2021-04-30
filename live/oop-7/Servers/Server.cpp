#include "Server.h"

using std::cout;
using std::cin;

Server::Server()
{
	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = 0;
	}

	this->OS = nullptr;
	this->Memory = 0;
	this->RAM = 0;
	this->CPU = 0;
}

Server::Server(const Server& s)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = s.IPv4Address[i];
	}

	unsigned sOSLen = strlen(s.OS);
	this->OS = new char[sOSLen + 1];
	strcpy_s(this->OS, sizeof(char) * (sOSLen + 1), s.OS);
	this->OS[sOSLen] = '\0';

	this->Memory = s.Memory;
	this->RAM = s.RAM;
	this->CPU = s.CPU;
}

Server& Server::operator=(const Server& s)
{
	if (&s == this)
	{
		return *this;
	}

	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = s.IPv4Address[i];
	}

	unsigned sOSLen = strlen(s.OS);
	this->OS = new char[sOSLen + 1];
	strcpy_s(this->OS, sizeof(char) * (sOSLen + 1), s.OS);
	this->OS[sOSLen] = '\0';

	this->Memory = s.Memory;
	this->RAM = s.RAM;
	this->CPU = s.CPU;

	return *this;
}

Server::Server(Server&& s) noexcept
{
	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = s.IPv4Address[i];
		s.IPv4Address[i] = 0;
	}

	this->OS = s.OS;
	s.OS = nullptr;

	this->Memory = s.Memory;
	s.Memory = 0;

	this->RAM = s.RAM;
	s.RAM = 0;

	this->CPU = s.CPU;
	s.CPU = 0;
}

Server& Server::operator=(Server&& s) noexcept
{
	if (&s == this)
	{
		return *this;
	}

	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = s.IPv4Address[i];
		s.IPv4Address[i] = 0;
	}

	this->OS = s.OS;
	s.OS = nullptr;

	this->Memory = s.Memory;
	s.Memory = 0;

	this->RAM = s.RAM;
	s.RAM = 0;

	this->CPU = s.CPU;
	s.CPU = 0;
	return *this;
}

Server::~Server()
{
	delete[] this->OS;
}

bool Server::areAdressesEqual(int ip1[]) const {
	for (size_t i = 0; i < 4; i++)
	{
		if (this->IPv4Address[i] != ip1[i])
		{
			return false;
		}
	}

	return true;
}

bool Server::operator==(const Server& s) const
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->IPv4Address[i] != s.IPv4Address[i])
			return false;
	}

	if (strcmp(this->OS, s.OS) != 0)
	{
		return false;
	}

	if (this->Memory != s.Memory)
		return false;

	if (this->RAM != s.RAM)
		return false;

	if (this->CPU != s.CPU)
		return false;

	return true;
}

void Server::print() const
{
	cout << "\nIPv4Address: ";
	for (size_t i = 0; i < 4; i++)
	{
		cout << this->IPv4Address[i] << '.';
	}

	cout << "\nOS: " << this->OS;
	cout << "\nMemory: " << this->Memory;
	cout << "\nRAM: " << this->RAM;
	cout << "\nCPU: " << this->CPU;
}

void Server::read()
{
	char buffer[100];

	cout << "\nEnter IPv4Address: ";
	for (size_t i = 0; i < 4; i++)
	{
		cin >> this->IPv4Address[i];
	}

	cout << "Enter OS name: ";
	cin.ignore();
	cin.getline(buffer, 100);
	unsigned buffLen = strlen(buffer);

	if (buffLen > 20)
	{
		throw std::invalid_argument("OS name cannot exceed 20 symbols.");
	}

	this->OS = new char[buffLen + 1];
	strcpy_s(this->OS, sizeof(char) * (buffLen + 1), buffer);

	cin >> this->Memory;
	if (this->Memory < 1)
	{
		delete[] this->OS;
		throw std::invalid_argument("Memory cannot be less than 1");
	}

	cin >> this->RAM;
	if (this->RAM < 1)
	{
		delete[] this->OS;
		throw std::invalid_argument("RAM cannot be less than 1");
	}

	cin >> this->CPU;
	if (this->CPU < 1)
	{
		delete[] this->OS;
		throw std::invalid_argument("CPU GHz cannot be less than 1");
	}
}

int Server::operator<(const Server& s) const
{
	for (size_t i = 0; i < 4; i++)
	{
		int first = this->IPv4Address[i];
		int second = s.IPv4Address[i];
		if (first < second)
		{
			return first - second;
		}
		else if (first > second)
		{
			return first - second;
		}
	}

	return 0;
}
