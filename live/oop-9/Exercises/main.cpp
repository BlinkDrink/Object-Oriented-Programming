#include "Pizza.h"
#include "Salad.h"

int main() {
	double w = 400;
	size_t parts = 5;
	double price = 2.5;

	Pizza p(w, parts, price, "margarita");
	p.print();
	p.consume();
	p.print();

	Salad s(w, parts, price, 5, 1);
	s.print();
	s.consume();
	s.print();

	return 0;
}