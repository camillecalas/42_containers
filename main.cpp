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
	ft::map<int, int>a;
	a.insert(ft::pair<int, int>(1, 100));
	a.insert(ft::pair<int, int>(2, 200));
	a.insert(ft::pair<int, int>(3, 300));
	a.print_tree();
	ft::map<int,int>::iterator it = a.begin();
	// std::cout << it->first << std::endl;
	// a[1] = 10;
	
	// RedBlackTree bst;
	// bst.insert(55);
	// bst.insert(40);
	// bst.insert(65);
	// bst.insert(60);
	// bst.insert(75);
	// bst.insert(57);

	// bst.printTree();
	// std::cout << std::endl << "After deleting" << std::endl;
	// bst.deleteNode(40);
	// bst.printTree();

	return (0);
}




