#include "ServerCluster.h"

ServerCluster::ServerCluster(size_t capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->servers = new Server * [capacity];
}

bool ServerCluster::isInCluster(Server& s) const {
	for (size_t i = 0; i < this->size; i++)
	{
		if (*this->servers[i] == s)
		{
			return true;
		}
	}

	return false;
}

void ServerCluster::print() const {
	for (size_t i = 0; i < this->size; i++)
	{
		this->servers[i]->print();
	}
}

ServerCluster& ServerCluster::addServer(Server& s) {
	if (this->size + 1 >= this->capacity)
	{
		throw std::invalid_argument("Cannot add more servers to the cluster.");
	}

	if (isInCluster(s))
	{
		throw std::invalid_argument("Server already exists in the cluster");
	}

	this->servers[this->size] = &s;
	this->size++;

	return *this;
}

unsigned ServerCluster::countInNetwork() const {
	int count = 0;

	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = i + 1; j < this->size - 1; j++)
		{
			if (this->servers[i]->IPv4Address[0] == this->servers[j]->IPv4Address[0])
			{
				count++;
			}
		}
	}

	return count;
}

ServerCluster ServerCluster::operator-=(int IPv4Address[]) {
	bool isInCluster = true;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (this->servers[i]->IPv4Address[j] != IPv4Address[j])
			{
				isInCluster = false;
			}
		}
	}

	if (!isInCluster)
	{
		throw std::invalid_argument("Server does not exist in the cluster.");
	}

	unsigned ind = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->servers[i]->areAdressesEqual(IPv4Address))
		{
			ind = i;
			break;
		}
	}

	this->servers[ind] = nullptr;
	std::swap(this->servers[ind], this->servers[this->size - 1]);

	this->size--;

	return *this;
}

ServerCluster::~ServerCluster() {
	delete[] this->servers;
}