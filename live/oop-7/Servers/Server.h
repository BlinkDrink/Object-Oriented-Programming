#pragma once
#include<iostream>
#include<cstring>

class Server {
private:
	char* OS;
	int Memory;
	int RAM;
	float CPU;
public:
	int IPv4Address[4];
	Server();

	Server(const Server& s);
	Server& operator=(const Server& s);

	Server(Server&& s) noexcept;
	Server& operator=(Server&& s) noexcept;

	~Server();

	bool areAdressesEqual(int ip1[]) const;
	bool operator==(const Server& s) const;
	void print() const;
	void read();
	int operator<(const Server& s) const;
};