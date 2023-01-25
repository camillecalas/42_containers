#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include "pair.hpp"
#include "map.hpp"

#include "node.hpp"
// #include "red_black_tree.hpp"
#include <vector>
#include <map>


#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

using namespace TESTED_NAMESPACE;


int main()
{

	std::cout << "*******STD******\n";
	std::map<int, int>c;
	c.insert(std::pair<int, int>(1, 100));
	c.insert(std::pair<int, int>(2, 200));
	c.insert(std::pair<int, int>(3, 300));
	c.insert(std::pair<int, int>(45, 4500));
	c.insert(std::pair<int, int>(24, 2400));
	std::map<int,int>::iterator it2 = c.find(45);
	std::cout << it2->first << std::endl;
	// c.insert (it2, std::pair<int,int>(77,7700));  
	// // c.print_tree();
	// std::cout << "\n" << "******************\n";
	// std::map<int,int> d;
	// d.insert(c.begin(),c.find(45));
	// // d.print_tree();

	std::cout << "\n*******FT******\n";

	ft::map<int, int>a;
	a.insert(ft::pair<int, int>(1, 100));
	a.insert(ft::pair<int, int>(2, 200));
	a.insert(ft::pair<int, int>(3, 300));
	a.insert(ft::pair<int, int>(45, 4500));
	a.insert(ft::pair<int, int>(24, 2400));
	ft::map<int,int>::iterator it = a.begin();
	a.insert (it, ft::pair<int,int>(77,7700));  
	a.print_tree();
	// std::cout << "\n" << "******************\n";
	// ft::map<int,int>::iterator it = a.find(45);
	// std::cout << it->first << std::endl;
	// a.erase(it);
	// if (it != a.end())
	// a.insert (it, ft::pair<int,int>(77,7700)); 
	// a.print_tree();



	// std::cout << "\n" << "******************\n";
	// ft::map<int,int> b;
	// b.insert(a.begin(), a.find(1));
	// b.print_tree();


	return (0);
}




