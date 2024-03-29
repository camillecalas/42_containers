
#include <list>
#include "../test.hpp"

#define T1 char
#define T2 int


typedef NAMESPACE::pair<const T1, T2> T3;

void
print_map(NAMESPACE::map<T1, T2> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	NAMESPACE::map<T1, T2>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " = " << it->second << std::endl;
}


template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}


int main()
{
	srand(time(NULL));

	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));

	NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
	NAMESPACE::map<T1, T2>::iterator it;

	lst.clear();
	is_empty(mp);
	std::cout << "1 -------------------\n";
	std::cout << "mp SIZE = "<< mp.size() << std::endl;
	print_map(mp);

	is_empty(mp2);
	mp2 = mp;
	is_empty(mp2);

	it = mp.begin();

	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	std::cout << "2 -------------------\n";
	std::cout << "mp SIZE = "<< mp.size() << std::endl;
	print_map(mp);
	std::cout << "3 -------------------\n";
	std::cout << "mp SIZE = "<< mp.size() << std::endl;
	print_map(mp2);

	mp2.clear();
	is_empty(mp2);
	std::cout << "4 -------------------\n";
	print_map(mp2);
	return (0);
}
