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
	std::vector<int>b(5);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	ft::vector<int> a(10);
	std::cout << a.at(100) << std::endl;
	// for (size_t i = 0; i < 10; i++)
	// 	std::cout << a[i] << std::endl;
	ft::vector<int>::iterator it;
	int x = 0;
	for (it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
		std::cout << x++ << std::endl;
	return (0);
}