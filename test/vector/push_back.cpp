
#include "../test.hpp"

int main()
{
	srand(time(NULL));
	
	NAMESPACE::vector<TESTED_TYPE> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);
	for (size_t i = 0; i < b.size(); i++)
		std::cout << "i = " << i << "   "<< b[i] << std::endl;
	std::cout << std::endl;
	b.resize(8);
	for (size_t i = 0; i < b.size(); i++)
		std::cout << "i = " << i << "   "<< b[i] << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	return (0);
}