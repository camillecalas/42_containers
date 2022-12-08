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
	std::vector<int> b;
	b.assign(5,100);
	std::vector<int>::iterator it2;
	it2 = b.begin() + 1;
	b.assign(it2, b.end() - 1);
	// b.push_back(1);
	// b.push_back(2);
	// b.push_back(3);
	// b.push_back(4);
	// b.push_back(5);
	// b.push_back(6);
	// b.push_back(7);
	// b.push_back(8);
	// for (size_t i = 0; i < b.size(); i++)
	// 	std::cout << "i = " << i << "   "<< b[i] << std::endl;
	// std::cout << std::endl;
	// b.resize(8);
	// // b.erase(b.begin() + 3);
	// // b.erase(b.begin() + 3, b.begin() + 5);
	for (size_t i = 0; i < b.size(); i++)
		std::cout << "i = " << i << "   "<< b[i] << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	std::cout << "************************"<< std::endl;

	ft::vector<int> a;
	a.assign(5,100);
	ft::vector<int>::iterator it;
	it = a.begin() + 1;
	a.assign(it, a.end() - 1);
	// std::cout << (*(a.begin() + 1)) << std::endl;
	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// a.push_back(5);
	// a.push_back(6);
	// a.push_back(7);
	// a.push_back(8);
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << "i = " << i << "   "<< a[i] << std::endl;
	// std::cout << std::endl;
	// // a.erase(a.begin() + 3);
	// // a.erase(a.begin() + 3, a.begin() + 5);
	// a.resize(8);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << "i = " << i << "   "<< a[i] << std::endl;
	// for (it = a.begin(); it != a.end(); it++)
	// 	std::cout << "i = " << *it << std::endl;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << b.capacity() << std::endl;


	return (0);
}