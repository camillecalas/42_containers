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
	std::vector<int> c;
	std::vector<int> d;

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.push_back(4);
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.push_back(4);

	d.push_back(5);
	d.push_back(6);
	d.push_back(7);
	d.push_back(8);

	c.swap(d);
	std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;


	std::vector<int>::iterator it2;
		
	for (it2 = c.begin(); it2 != c.end(); it2++)
		std::cout << *it2 << std::endl;
	std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;

	std::cout << "************************"<< std::endl;


	ft::vector<int> a;
	ft::vector<int> b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);

	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);

	b.swap(a);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	ft::vector<int>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;



	return (0);
}