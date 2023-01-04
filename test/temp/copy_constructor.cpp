#include "../test.hpp"

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

int main()
{

	srand(time(NULL));
	std::cout << "TEST: COPY CONSTRUCTOR\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

	NAMESPACE::vector<TESTED_TYPE> b;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);

	NAMESPACE::vector<TESTED_TYPE> c(b);

	print_vector(b);
	print_vector(c);


	{
		NAMESPACE::vector<TESTED_TYPE> vct(5);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

		std::cout << "len: " << (ite - it) << std::endl;
		for (; it != ite; ++it)
			*it = (ite - it);

		it = vct.begin();
		NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			*it = ++i * 5;

		it = vct.begin();
		NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
		for (int i = 0; it != ite; ++it)
			*it = ++i * 7;
		vct_copy.push_back(42);
		vct_copy.push_back(21);

		std::cout << "\t-- PART ONE --" << std::endl;
		std::cout << "SIZE = " << vct.size() << " CAPACITY = " << vct.capacity() << std::endl;
		std::cout << "SIZE = " << vct_range.size() << " CAPACITY = " << vct_range.capacity() << std::endl;
		std::cout << "SIZE = " << vct_copy.size() << " CAPACITY = " << vct_copy.capacity() << std::endl;

		vct = vct_copy;
		vct_copy = vct_range;
		vct_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;
		std::cout << "SIZE = " << vct.size() << " CAPACITY = " << vct.capacity() << std::endl;
		std::cout << "SIZE = " << vct_range.size() << " CAPACITY = " << vct_range.capacity() << std::endl;
		std::cout << "SIZE = " << vct_copy.size() << " CAPACITY = " << vct_copy.capacity() << std::endl;
	}

	return (0);

}