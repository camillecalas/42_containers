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
	std::cout << "TEST: INSERT\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

		{
		NAMESPACE::vector<TESTED_TYPE> vct;

		vct.insert(vct.begin(), 42);
		vct.push_back(10);
		vct.push_back(11);
		vct.insert(vct.begin() + 1, 2);
		print_vector(vct);

	}

	{
		NAMESPACE::vector<TESTED_TYPE> vct(10);
		NAMESPACE::vector<TESTED_TYPE> vct2;
		NAMESPACE::vector<TESTED_TYPE> vct3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		print_vector(vct);

		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		print_vector(vct2);

		vct2.insert(vct2.end() - 2, 42);
		print_vector(vct2);

		vct2.insert(vct2.end(), 2, 84);
		print_vector(vct2);

		vct2.resize(4);
		print_vector(vct2);

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		print_vector(vct2);

		print_vector(vct);

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		vct3.insert(vct3.begin() + 1, 2, 111);
		print_vector(vct3);

	}

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
	print_vector(b);
	
	b.insert(b.end() - 3, 4, 10);
	print_vector(b);
	
	b.insert(b.begin() + 3, 10, 10);
	print_vector(b);

	b.insert(b.begin() + 2, b.begin() + 3, b.end());
	print_vector(b);

	b.insert(b.begin() + 5, b.begin() + 1, b.end());
	print_vector(b);


  	int myarray [] = { 501,502,503,504 };
  	b.insert (b.begin(), myarray, myarray+3);
	print_vector(b);

	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "SIZE = " << b.size() << " CAPACITY = " << b.capacity() << std::endl;


	std::cout << "********************************\n";
	{
		NAMESPACE::vector<TESTED_TYPE> vct(5);
		NAMESPACE::vector<TESTED_TYPE> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		std::cout << "insert return:" << std::endl;

		std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
		return (0);
	}

	std::cout << "********************************\n";
	{
		NAMESPACE::vector<TESTED_TYPE> vct(10);
		NAMESPACE::vector<TESTED_TYPE> vct2;
		NAMESPACE::vector<TESTED_TYPE> vct3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		std::cout << "SIZE = " << vct.size() << " CAPACITY = " << vct.capacity() << std::endl;

		vct2.insert(vct2.end(), 42);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;
		vct2.insert(vct2.begin(), 2, 21);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		vct2.insert(vct2.end() - 2, 42);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		vct2.insert(vct2.end(), 2, 84);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		vct2.resize(4);
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		std::cout << "SIZE = " << vct2.size() << " CAPACITY = " << vct2.capacity() << std::endl;

		std::cout << "SIZE = " << vct.size() << " CAPACITY = " << vct.capacity() << std::endl;

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		vct3.insert(vct3.begin() + 1, 2, 111);
		std::cout << "SIZE = " << vct3.size() << " CAPACITY = " << vct3.capacity() << std::endl;

		print_vector(vct3);

	}

	return (0);
}