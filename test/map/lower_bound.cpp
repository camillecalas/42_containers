#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: COUNT\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2>::iterator itlow, itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		std::cout << itlow->first << " = " << itlow->second << std::endl;
		std::cout << itup->first << " = " << itup->second << std::endl;

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';


	}
		return (0);
}
