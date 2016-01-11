#include <iostream>
#include "../SDP_dom_4/Tree.h"
#include <sstream>

void work(std::istream&);

int main()
{

	std::string INPUT = "\
(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})\n\
(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})\n\
";
	std::istringstream iss(INPUT);

	//work(std::cin);
	work(iss);

	return 0;
}


void work(std::istream& iss)
{
	Tree a, b;

	std::string buf;

	std::getline(iss, buf);
	a.build(buf);

	std::getline(iss, buf);
	b.build(buf);

	//a.build("(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})");
	//b.build("(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})");

	//a.AssigCanonName();
	//b.AssigCanonName();

	if (a.AreIsomorphic(b))
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}
