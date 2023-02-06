
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

	NAMESPACE::map<T1, T2> mp;
	
	std:: cout << mp.max_size() << std::endl;
	return (0);
}
