
#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: ERASE";

	NAMESPACE::vector<TESTED_TYPE> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);

	b.erase(b.begin() + 2, b.end() - 2);

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	
	b.erase(b.begin() + 2);

	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	return (0);
}