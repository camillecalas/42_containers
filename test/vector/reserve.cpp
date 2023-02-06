
#include "../test.hpp"

// #include "VECTOR_UC.HPP"
#include <vector>

// #ifndef STD
// # define NAMESPACE ft
// #else
// # define NAMESPACE std
// #endif

// using namespace NAMESPACE;

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}


int main ()
{
  NAMESPACE::vector<int>::size_type sz;

  NAMESPACE::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  NAMESPACE::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  try
  {
	bar.reserve(bar.max_size() * 2);
  }
  catch(std::exception& e) { std::cout << e.what(); }
  return 0;
}
