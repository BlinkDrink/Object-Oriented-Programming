#include "Server.h"

class ServerCluster {
private:
	Server** servers;
	unsigned size;
	unsigned capacity;
public:
	ServerCluster(size_t capacity);

	void print() const;

	ServerCluster& addServer(Server& s);
	unsigned countInNetwork() const;
	ServerCluster operator-=(int IPv4Address[]);

	bool isInCluster(Server& s) const;

	~ServerCluster();
};