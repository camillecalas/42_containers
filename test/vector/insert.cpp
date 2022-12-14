#include "../test.hpp"

int main()
{

	srand(time(NULL));
	std::cout << "TEST: RESIZE\n";
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

	b.insert(b.begin() + 3, 10);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	
	// b.insert(b.end() - 3, 4, 10);
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	
	// b.insert(b.begin() + 3, 10, 10);
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	// b.insert(b.begin() + 2, b.begin() + 1, b.end());
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


  	int myarray [] = { 501,502,503 };
  	b.insert (b.begin(), myarray, myarray+3);

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	std::cout << "********************************\n";
	{

		

	}

	return (0);
}