#include "../test.hpp"

int main()
{

	srand(time(NULL));
	std::cout << "TEST: INSERT\n";
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
	
	b.insert(b.end() - 3, 4, 10);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;
	
	b.insert(b.begin() + 3, 10, 10);
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	b.insert(b.begin() + 2, b.begin() + 3, b.end());
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;

	// b.insert(b.begin() + 5, b.begin() + 1, b.end());
	// std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


  	// int myarray [] = { 501,502,503,504 };
	// int	*tmp = &myarray[1];
  	// b.insert (b.begin(), myarray, tmp);
  	// b.insert (b.begin(), myarray, myarray+3);

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
		
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	// std::cout << "********************************\n";
	// {
	// 	NAMESPACE::vector<TESTED_TYPE> vct(5);
	// 	NAMESPACE::vector<TESTED_TYPE> vct2;
	// 	const int cut = 3;

	// 	for (unsigned long int i = 0; i < vct.size(); ++i)
	// 		vct[i] = (vct.size() - i) * 7;
	// 	std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

	// 	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	// 	std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
	// 	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	// 	std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
	// 	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	// 	std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

	// 	std::cout << "insert return:" << std::endl;

	// 	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	// 	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	// 	std::cout << "----------------------------------------" << std::endl;

	// 	std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
	// 	return (0);
	// }

	return (0);
}