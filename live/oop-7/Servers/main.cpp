#include "ServerCluster.h"

using std::cout;

struct Test {
	std::uint8_t a;
	std::uint32_t b;
	struct {
		std::uint32_t c;
		std::uint16_t d;
	};
};

int main() {
	ServerCluster sc(10);

	Server s;
	Server t;
	s.read();
	s.print();

	t.read();
	t.print();


	sc.addServer(s).addServer(t).print();

	cout << '\n' << (s == t) << '\n';
	cout << (s < t) << '\n';

	return 0;
}