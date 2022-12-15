#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <stdexcept>  
# include <string>
# include <sstream>




# define NAME_SPACE_START namespace ft{
# define NAME_SPACE_END	};

# define ENABLE_IF typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type

#endif