#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include "pair.hpp"

#include "node.hpp"
// #include "red_black_tree.hpp"
#include <vector>
#include <map>

using namespace NAMESPACE;

template <class Key, class T>
void	print(NAMESPACE::map<Key, T>& lst)
{
	for (typename std::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}


// int main()
// {
// 	{


// 		std::std::map<char,int> foo,bar;

// 		foo['x']=100;
// 		foo['y']=200;

// 		bar['a']=11;
// 		bar['b']=22;
// 		bar['c']=33;

// 		swap(foo,bar);

// 		std::std::cout << "foo contains:\n";
// 		for (std::std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		std::std::cout << "bar contains:\n";
// 		for (std::std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

		
// 	}

// 	{
// 		std::std::cout << "\n*******FT******\n";

// 		ft::std::map<char,int> foo,bar;

// 		foo['x']=100;
// 		foo['y']=200;

// 		bar['a']=11;
// 		bar['b']=22;
// 		bar['c']=33;

// 		swap(foo,bar);

// 		std::std::cout << "foo contains:\n";
// 		for (ft::std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		std::std::cout << "bar contains:\n";
// 		for (ft::std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		return 0;
// 	}

// 	return (0);
// }




