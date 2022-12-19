#include "../test.hpp"

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

int		main(void)
{
	std::cout << "OK1" << std::endl;
	NAMESPACE::vector<TESTED_TYPE> vct;
	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	vct.push_back(3);
	vct.push_back(2);
	vct.push_back(1);
	vct.push_back(4);
	vct.push_back(5);
	vct.push_back(6);
	vct.push_back(7);
	vct.push_back(8);

	NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

	
	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);
	std::cout << "OK2" << std::endl;
	/* error expected
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}