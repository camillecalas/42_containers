#include "../test.hpp"

int main()
{

	srand(time(NULL));
	std::cout << "TEST: RESIZE\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

	NAMESPACE::vector<TESTED_TYPE> b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);

	b.resize(4);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	b.resize(8, 100);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	b.resize(12);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	NAMESPACE::vector<TESTED_TYPE>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	std::cout << "********************************\n";

	NAMESPACE::vector<TESTED_TYPE> a;

	a.resize(4);

	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(50, 100);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(5);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(2);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(50);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;


	NAMESPACE::vector<TESTED_TYPE>::iterator it2;
		
	for (it2 = a.begin(); it2 != a.end(); it2++)
		std::cout << *it2 << std::endl;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;


	return (0);
}