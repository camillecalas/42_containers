#include "../test.hpp"

int main()
{

	srand(time(NULL));
	std::cout << "TEST: SWAP\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

	NAMESPACE::vector<TESTED_TYPE> b;
	NAMESPACE::vector<TESTED_TYPE> a;

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);

	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);

	b.swap(a);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	NAMESPACE::vector<TESTED_TYPE>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	std::cout << "********************************\n";
	{

		NAMESPACE::vector<TESTED_TYPE> b;
		NAMESPACE::vector<TESTED_TYPE> a;

		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		b.push_back(4);
		b.push_back(1);
		b.push_back(2);
		b.push_back(3);
		b.push_back(4);

		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);

		a.swap(b);
		std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


		NAMESPACE::vector<TESTED_TYPE>::iterator it;
			
		for (it = b.begin(); it != b.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	}



	return (0);
}