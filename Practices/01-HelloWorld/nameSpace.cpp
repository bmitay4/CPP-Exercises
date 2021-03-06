//Exmaple of using namespace and the importancy of using it correctly
#include <iostream>

namespace abc{
	int x = 123;
	void printx() { std::cout << x << std::endl; }

	namespace xyz {
		int w = 5;
	}
};

namespace def{
	int x = 456;
	void printx() { std::cout << x << std::endl; }
};

using namespace abc;
using namespace def;
int main() {
  // printx();
  //Can't call printx(), its ambiguous!

	abc::printx();
	def::printx();
	std::cout << abc::xyz::w << std::endl;
}

/*
OUTPUT

123
456
5

*/
