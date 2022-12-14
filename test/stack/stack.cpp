#include "../test.hpp"

void
print_vector(NAMESPACE::vector<TESTED_TYPE> & v) {
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
	NAMESPACE::vector<TESTED_TYPE>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

// int main()
// {

// 	srand(time(NULL));
// 	std::cout << "TEST: STACK\n";

// 	NAMESPACE::stack<TESTED_TYPE> stack;

// 	stack.push(3);
// 	stack.push(5);

// 	std::cout << stack.top() << std::endl;
// 	stack.push(21);
//     stack.push(22);
//     stack.push(24);
//     stack.push(25);
       
//     stack.pop();
//     stack.pop();
   
//     while (!stack.empty()) {
//         std::cout << stack.top() <<" ";
//         stack.pop();
//     }

// 	NAMESPACE::stack<TESTED_TYPE> stack2;

// 	stack2 = stack;
// 	while (!stack2.empty()) {
//         std::cout << stack2.top() <<" ";
//         stack2.pop();
//     }
// }



#include <list>

#define TESTED_TYPE int
typedef std::list<TESTED_TYPE> container_type;
#define t_stack_ NAMESPACE::stack<TESTED_TYPE, container_type>

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_	stck(ctnr);
	t_stack_	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7
	return (0);
}