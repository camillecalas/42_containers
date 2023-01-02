#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include <vector>


#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

using namespace TESTED_NAMESPACE;


int main()
{

	std::cout << "TEST: CLEAR\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

	std::vector<int> b;

	for (size_t i = 0; i < 1000; i++)
		b.push_back(i);
	b.clear();
	b.pop_back();
	// NAMESPACE::vector<TESTED_TYPE> c(b);
	// std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;
	// b.resize(4);
	// for (size_t i = 0; i < 3; i++)
	// 	b.push_back(i);
	// b.pop_back();

	std::vector<int>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	// std::cout << "************************"<< std::endl;


	// ft::vector<int> b(100);
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	// std::vector<int> a;

	// d.insert(a.begin(), 3, b);


	// b.push_back(1);
	// b.push_back(2);
	// b.push_back(3);
	// b.push_back(4);
	// b.push_back(5);
	// b.push_back(6);
	// b.push_back(7);
	// b.push_back(8);

	// ft::vector<int> d(0);
	// d.push_back(7);

	// for (size_t i = 0; i < d.size(); i++)
	// 	std::cout << "d[i] = " << d[i] << std::endl;
	// std::cout << "ICI\n";
	// if (b == d)
	// 	std::cout << "1TRUE\n";
	// if (b != d)
	// 	std::cout << "2TRUE\n";
		



	// b.insert(b.begin() + 2, b.begin() + 1, b.end());
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	// ft::vector<int>::iterator it;
	// ft::vector<int>::const_iterator it3 = b.begin();
	// it3[0] = 42;
	// int j = 0;
	// for (it = b.begin(); it != b.end(); it++)
	// 	std::cout << j++ << "    " << it << " = " << *it << std::endl;
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;



	return (0);
}