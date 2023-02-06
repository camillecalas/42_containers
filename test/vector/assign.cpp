#include "../test.hpp"

int main()
{

	srand(time(NULL));
	std::cout << "TEST: ASSIGN\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

	NAMESPACE::vector<TESTED_TYPE> b;

	b.assign(7, 100);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	it = b.begin() + 1;
	b.assign(it, b.end() - 1);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	for (size_t i = 0; i < 30; i++)
		b.push_back(i);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	b.assign(b.begin() + 20, b.end() - 10);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	// std::cout << "*****************************************\n";

	NAMESPACE::vector<TESTED_TYPE> first;
	NAMESPACE::vector<TESTED_TYPE> second;
	NAMESPACE::vector<TESTED_TYPE> third;

	first.assign (7,100);             // 7 ints with a value of 100

	NAMESPACE::vector<TESTED_TYPE>::iterator it2;
	it2 = first.begin()+1;

	second.assign (it2, first.end()-1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign (myints, myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';

	return (0);
}