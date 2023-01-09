#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include "pair.hpp"
#include <vector>


#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

using namespace TESTED_NAMESPACE;


int main()
{

	std::cout << "TEST: PAIR\n";

	std::pair<std::string, int> a;
	std::pair<std::string, int> b("DOG", 4);
	std::pair<std::string, int> c(b);
	std::cout << c.first << " = " << c.second << std::endl;

	
	// std::cout << "************************"<< std::endl;

	ft::pair<std::string, int> d;
	ft::pair<std::string, int> e("DOG", 4);
	ft::pair<std::string, int> f(e);
	std::cout << f.first << " = " << f.second << std::endl;

	// ft::pair<int,char> foo (10,'z');
	// ft::pair<int,char> bar (90,'a');

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

	



	return (0);
}




