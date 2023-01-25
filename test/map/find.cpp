#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: COUNT\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';

	}
		return (0);
}
