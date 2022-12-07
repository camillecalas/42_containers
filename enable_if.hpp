#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

NAME_SPACE_END
#endif