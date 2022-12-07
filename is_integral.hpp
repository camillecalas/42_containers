#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

// template <class T, T v>
// struct integral_constant
// {
// 	// static constexpr T value = v;
//  	// typedef T value_type;
//  	// typedef integral_constant<T,v> type;
//  	// constexpr operator T() { return v; }

// 	static const Tp					value = v;
// 		typedef Tp							value_type;
// 		typedef integral_constant<Tp, v>	type;
// 		//Returns the wrapped value. This function enables std::integral_constant to serve as a source of compile-time function objects.
// 		value_type operator() (void) const { return value; } 
// 		operator value_type() const { return value; } //its convertion operator  from integral_constant<T, v> to T
// };

// typedef integral_constant<bool, true>	true_type;
// typedef integral_constant<bool, false>	false_type;

// template <class T> struct is_integral: public false_type {};
// template <> struct is_integral<bool>: public true_type {};
// template <> struct is_integral<char>: public true_type {};
// template <> struct is_integral<signed char>: public true_type {};
// template <> struct is_integral<unsigned char>: public true_type {};
// template <> struct is_integral<wchar_t>: public true_type {};
// template <> struct is_integral<short>: public true_type {};
// template <> struct is_integral<unsigned short>: public true_type {};
// template <> struct is_integral<int>: public true_type {};
// template <> struct is_integral<unsigned int>: public true_type {};
// template <> struct is_integral<long>: public true_type {};
// template <> struct is_integral<unsigned long>: public true_type {};
// template <> struct is_integral<long long>: public true_type {};
// template <> struct is_integral<unsigned long long>: public true_type {};
// template <> struct is_integral<float>: public true_type {};
// template <> struct is_integral<double>: public true_type {};
// template <> struct is_integral<long double>: public true_type {};
// template <> struct is_integral<void>: public true_type {};




template<typename T, T v>
struct integral_const {
	typedef T	value_type;
	typedef integral_const<T, v> type;
	
	static const value_type 	value = v;
	
	operator value_type() {return (v);}
};

typedef integral_const<bool, true> true_type;
typedef integral_const<bool, false> false_type;

template<typename T> struct is_integral				: public false_type {};
template<>	struct is_integral<bool>				: public true_type {};
template<>	struct is_integral<char>				: public true_type {};
template<>	struct is_integral<signed char>			: public true_type {};
template<>	struct is_integral<unsigned char>		: public true_type {};
template<>	struct is_integral<wchar_t>				: public true_type {};
template<>	struct is_integral<short>				: public true_type {};
template<>	struct is_integral<unsigned short>		: public true_type {};
template<>	struct is_integral<int>					: public true_type {};
template<>	struct is_integral<unsigned int>		: public true_type {};
template<>	struct is_integral<long>				: public true_type {};
template<>	struct is_integral<long long>			: public true_type {};
template<>	struct is_integral<unsigned long>		: public true_type {};
template<>	struct is_integral<unsigned long long>	: public true_type {};

NAME_SPACE_END
#endif