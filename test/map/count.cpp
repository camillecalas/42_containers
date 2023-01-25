#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: COUNT\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{

		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}

	}
		return (0);
}

