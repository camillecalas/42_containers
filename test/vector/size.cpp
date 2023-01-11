#include "../test.hpp"

void	is_empty(NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}


int		main(void)
{
	const int start_size = 7;
	NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	NAMESPACE::vector<TESTED_TYPE> vct2;
	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	print_vector(vct);

	vct.resize(10, 42);
	print_vector(vct);

	vct.resize(18, 43);
	print_vector(vct);
	vct.resize(10);
	print_vector(vct);
	vct.resize(23, 44);
	print_vector(vct);
	vct.resize(5);
	print_vector(vct);
	vct.reserve(5);
	vct.reserve(3);
	print_vector(vct);
	vct.resize(87);
	vct.resize(5);
	print_vector(vct);

	is_empty(vct2);
	vct2 = vct;
	is_empty(vct2);
	vct.reserve(vct.capacity() + 1);
	print_vector(vct);
	print_vector(vct2);

	vct2.resize(0);
	is_empty(vct2);
	print_vector(vct2);
	return (0);
}
