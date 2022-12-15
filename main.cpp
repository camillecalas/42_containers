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

	// ft::vector<int> test2(3, 8);
    // std::cout << test2[2] << std::endl;

    // ft::vector<int> test3(test2.begin(), test2.end());
    // std::cout << test3[0] << std::endl;

    // ft::vector<int>::iterator first = test3.begin();
    // ft::vector<int>::iterator last = test3.end();

    // // (void)first;
    // // (void)last;

    // ft::vector<int> test4(first, last);
    // std::cout << test4[0] << std::endl;



	// std::vector<int> c;


	// c.push_back(1);
	// c.push_back(2);
	// c.push_back(3);
	// c.push_back(4);
	// c.push_back(5);
	// c.push_back(6);
	// c.push_back(7);
	// c.push_back(8);


	// c.insert(c.begin() + 2, c.begin() + 1, c.end());
	// std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;

	// std::vector<int>::iterator it2 = c.begin();
	// std::vector<int>::const_iterator it4 = c.begin();
	// it4[0] = 42;
	// int i = 0;
	// for (; it2 != c.end(); it2++)
	// 	std::cout << i++ << " = " << *it2 << std::endl;
	// std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;
	
	// std::cout << "************************"<< std::endl;


	ft::vector<int> b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);

	ft::vector<int> d(b);
	d.push_back(7);

	for (size_t i = 0; i < d.size(); i++)
		std::cout << "d[i] = " << d[i] << std::endl;
	std::cout << "ICI\n";
	if (b == d)
		std::cout << "1TRUE\n";
	if (b != d)
		std::cout << "2TRUE\n";
		

	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


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