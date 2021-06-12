#pragma once
#include "Spacecraft.h"
#include <vector>
#include <iostream>

using std::vector;
using spacecrafts = vector<Spacecraft>;

class System
{
public:
	System(const System& other) = delete;
	System& operator=(const System& other) = delete;
	~System();

	static System& getInstance();

	void readInput(const string& file, spacecrafts& spacecrafts);
	void serialize(const string& file, spacecrafts& spacecrafts) const;
	void deserialize(const string& file, spacecrafts& spacecrafts);

	void run();

private:
	System();

	spacecrafts m_spacecrafts;
};

