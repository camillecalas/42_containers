
#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: PUSH_BACK | POP_BACK";

	NAMESPACE::vector<TESTED_TYPE> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);

	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	for (size_t i = 0; i < 1000; i++)
		b.push_back(i);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	for (size_t i = 0; i < 10; i++)
		b.pop_back();
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	std::cout << std::endl;

	for (size_t i = 0; i < 1000; i++)
		b.push_back(i);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	return (0);
}