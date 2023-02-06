#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: AT\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{

		NAMESPACE::map<TESTED_TYPE3, TESTED_TYPE2> mymap;
		NAMESPACE::map<TESTED_TYPE3, TESTED_TYPE2>::iterator it;
		
		mymap["alpha"] = 0;
		mymap["beta"] = 0;
		mymap["gamma"] = 0;

		mymap.at("alpha") = 10;
		mymap.at("beta") = 20;
		mymap.at("gamma") = 30;

		for (it=mymap.begin(); it!=mymap.end(); ++it)
    		std::cout << it->first << " => " << it->second << '\n';
 	}

	return (0);
}