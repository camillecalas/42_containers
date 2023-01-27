#include "../test.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "TEST: SIZE\n";
	//Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
	{

		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		mymap.insert(NAMESPACE::pair<TESTED_TYPE, TESTED_TYPE2>('c', 402));
		mymap.insert(NAMESPACE::pair<TESTED_TYPE, TESTED_TYPE2>('d', 502));

		mymap.erase(mymap.find('a'));

		std::cout << "mymap.size() is " << mymap.size() << '\n';

	}

	{
		NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}

	}
	{
		int i;
		NAMESPACE::map<TESTED_TYPE2, TESTED_TYPE2> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
	}
	return (0);
}

