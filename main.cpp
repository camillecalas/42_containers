#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "equal.hpp"
#include "vector.hpp"
#include "pair.hpp"

#include "node.hpp"
// #include "red_black_tree.hpp"
#include <vector>
#include <map>

using namespace NAMESPACE;

template <class Key, class T>
void	print(NAMESPACE::map<Key, T>& lst)
{
	for (typename std::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	{
	std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;


	std::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	std::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	foo.swap(bar); //tmp iterates through bar
					//tmp2 iterates through foo


	std::map<char, int>	other;

	other['1'] = 73;
	other['2'] = 173;
	other['3'] = 763;
	other['4'] = 73854;
	other['5'] = 74683;
	other['6'] = 753;

	std::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		while(tmp != bar.end())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2++;
		}
		tmp2--;

		other.swap(foo); //tmp2 iterates through other
						//tmp3 iterates throught foo
		print(other);
		print(foo);
		print(bar);
		while(tmp != bar.begin())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp--;
		}
		std::cout << tmp->first << " => " << tmp->second << '\n';

		while(tmp2 != other.begin())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2--;
		}
		std::cout << tmp2->first << " => " << tmp2->second << '\n';

		while(tmp3 != foo.end())
		{
			std::cout << tmp3->first << " => " << tmp3->second << '\n';
			tmp3++;
		}
		tmp3--;

		bar.swap(foo); //tmp3 iterates through bar
					//tmp iterates through foo

		print(other);
		print(foo);
		print(bar);

		while(tmp != foo.end())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			std::cout << tmp3->first << " => " << tmp3->second << '\n';
			tmp3--;
		}
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
	}
	
	{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;


		ft::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
		ft::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

		foo.swap(bar); //tmp iterates through bar
						//tmp2 iterates through foo


		ft::map<char, int>	other;

		other['1'] = 73;
		other['2'] = 173;
		other['3'] = 763;
		other['4'] = 73854;
		other['5'] = 74683;
		other['6'] = 753;

		ft::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		while(tmp != bar.end())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2++;
		}
		tmp2--;

		other.swap(foo); //tmp2 iterates through other
						//tmp3 iterates throught foo
		print(other);
		print(foo);
		print(bar);
		while(tmp != bar.begin())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp--;
		}
		std::cout << tmp->first << " => " << tmp->second << '\n';

		while(tmp2 != other.begin())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2--;
		}
		std::cout << tmp2->first << " => " << tmp2->second << '\n';

		while(tmp3 != foo.end())
		{
			std::cout << tmp3->first << " => " << tmp3->second << '\n';
			tmp3++;
		}
		tmp3--;

		bar.swap(foo); //tmp3 iterates through bar
					//tmp iterates through foo

		print(other);
		print(foo);
		print(bar);

		while(tmp != foo.end())
		{
			std::cout << tmp->first << " => " << tmp->second << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			std::cout << tmp2->first << " => " << tmp2->second << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			std::cout << tmp3->first << " => " << tmp3->second << '\n';
			tmp3--;
		}
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
	}

  return 0;
}



// int main()
// {
// 	{


// 		std::std::map<char,int> foo,bar;

// 		foo['x']=100;
// 		foo['y']=200;

// 		bar['a']=11;
// 		bar['b']=22;
// 		bar['c']=33;

// 		swap(foo,bar);

// 		std::std::cout << "foo contains:\n";
// 		for (std::std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		std::std::cout << "bar contains:\n";
// 		for (std::std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

		
// 	}

// 	{
// 		std::std::cout << "\n*******FT******\n";

// 		ft::std::map<char,int> foo,bar;

// 		foo['x']=100;
// 		foo['y']=200;

// 		bar['a']=11;
// 		bar['b']=22;
// 		bar['c']=33;

// 		swap(foo,bar);

// 		std::std::cout << "foo contains:\n";
// 		for (ft::std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		std::std::cout << "bar contains:\n";
// 		for (ft::std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 		std::std::cout << it->first << " => " << it->second << '\n';

// 		return 0;
// 	}

// 	return (0);
// }




