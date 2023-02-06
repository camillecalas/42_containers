#include "../test.hpp"

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

// int main()
// {

// 	srand(time(NULL));
// 	std::cout << "TEST: INSERT\n";
// 	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

// 	NAMESPACE::vector<TESTED_TYPE> b;

// 	b.push_back(1);
// 	b.push_back(2);
// 	b.push_back(3);
// 	b.push_back(4);
// 	b.push_back(5);
// 	b.push_back(6);
// 	b.push_back(7);
// 	b.push_back(8);
// 	b[2] = 10;

// 	// NAMESPACE::vector<TESTED_TYPE> c(b);

// 	print_vector(b);
// 	// print_vector(c);

// 	return (0);

// }



// #define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const NAMESPACE::vector<T, Alloc> &lhs, const NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	NAMESPACE::vector<TESTED_TYPE> vct(4);
	NAMESPACE::vector<TESTED_TYPE> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7

	print_vector(vct);
	print_vector(vct2);

	return (0);
}