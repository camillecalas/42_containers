#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include <vector>


int main()
{
	ft::vector<int> a(10);
	a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// for (size_t i = 0; i < 10; i++)
	// 	std::cout << a[i] << std::endl;
	ft::vector<int>::iterator it;
	// int x = 0;
	// for (it = a.begin(); it != a.end(); it++)
	// 	std::cout << x++ << std::endl;
		// std::cout << *it << std::endl;
	return (0);
}