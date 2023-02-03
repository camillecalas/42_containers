#include "../test.hpp"



int		main(void)
{
	// NAMESPACE::map<T1, T2> mp, mp2;

    NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> foo;
     NAMESPACE::map<TESTED_TYPE, TESTED_TYPE2> bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    swap(foo,bar);

    std::cout << "foo contains:\n";
    for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
