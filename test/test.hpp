#ifndef TEST_HPP
# define TEST_HPP

#include "../Iterator.hpp"
#include "../vector.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../is_integral.hpp"
#include "../enable_if.hpp"

# define TESTED_TYPE 	int
# define _VECTOR 		NAMESPACE::vector<TESTED_TYPE>

template <typename T>
void
putVector (NAMESPACE::vector<T> const &v)
{
	typename NAMESPACE::vector<T>::const_iterator ite = v.end();
	typename NAMESPACE::vector<T>::const_iterator it = v.begin();

	for (; it != ite; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << ("") << std::endl;
	std::cout << (v.size()) << std::endl;
	std::cout << (v.max_size()) << std::endl;
	std::cout << (v.capacity()) << std::endl;
	std::cout << (v.empty()) << std::endl;
	
	std::cout << std::endl;
}


#endif