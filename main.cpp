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

	std::map<char,int> mymap;
	 std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "*******STD******\n";
	// std::map<int, int>c;
	// c.insert(std::pair<int, int>(1, 100));
	// c.insert(std::pair<int, int>(2, 200));
	// c.insert(std::pair<int, int>(3, 300));
	// c.insert(std::pair<int, int>(45, 4500));
	// c.insert(std::pair<int, int>(24, 2400));
	// std::map<int,int>::iterator it2 = c.find(45);
	// std::cout << it2->first << std::endl;


	// c.insert (it2, std::pair<int,int>(77,7700));  
	// // c.print_tree();
	// std::cout << "\n" << "******************\n";
	// std::map<int,int> d;
	// d.insert(c.begin(),c.find(45));
	// // d.print_tree();

	std::cout << "\n*******FT******\n";

	// ft::map<int, int>a;
	// a.insert(ft::pair<int, int>(1, 100));
	// a.insert(ft::pair<int, int>(2, 200));
	// a.insert(ft::pair<int, int>(3, 300));
	// a.insert(ft::pair<int, int>(45, 4500));
	// a.insert(ft::pair<int, int>(24, 2400));
	// ft::map<int,int>::iterator it = a.begin();
	// a.insert (it, ft::pair<int,int>(77,7700));  
	// a.print_tree();
	// std::cout << "\n" << "******************\n";
	// ft::map<int,int>::iterator it1 = a.find(45);
	// std::cout << it1->first << std::endl;
	// a.erase(it1);
	// // if (it1 != a.end())
	// // a.insert (it1, ft::pair<int,int>(77,7700)); 
	// a.print_tree();





	ft::map<char,int> mymap2;
	ft::map<char,int>::iterator it2;

  // insert some values:
  mymap2['a']=10;
  mymap2['b']=20;
  mymap2['c']=30;
  mymap2['d']=40;
  mymap2['e']=50;
  mymap2['f']=60;

  it2=mymap2.find('b');
  mymap2.erase (it2);                   // erasing by iterator

  mymap2.erase ('c');                  // erasing by key

  it2=mymap2.find ('e');
  mymap2.erase ( it2, mymap2.end() );    // erasing by range

//   show content:
  for (it2=mymap2.begin(); it2!=mymap2.end(); ++it2)
    std::cout << it2->first << " => " << it2->second << '\n';


	// std::cout << "\n" << "******************\n";
	// ft::map<int,int> b;
	// b.insert(a.begin(), a.find(1));
	// b.print_tree();


	return (0);
}




