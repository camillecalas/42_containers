#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: CLEAR\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "mymap contains:\n";
		for (NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
		return (0);
}
