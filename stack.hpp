#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

NAME_SPACE_START

template <class T, class Container = ft::vector<T> >
class stack
{
    // =============================================================================
    // TYPEDEF =====================================================================
    // typedef typename: You are not actually creating a new data type,but rather defining a new name for an existing type.
public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef std::size_t size_type;


    // =============================================================================
    // ATTRIBUTS ===================================================================
protected:
    container_type  _c;


    // =============================================================================
    // CONSTRUCTORS ================================================================
    // Allocate return a pointer to the initial element in the block of storage
public: 
    explicit
    stack (const container_type& ctnr = container_type())
        : _c(ctnr)
    {}


    // =============================================================================
    // DESTRUCTORS =================================================================
    ~stack()
    {}


    // =============================================================================
    // OVERLOADS ===================================================================
    stack& 
    operator=( const stack& other )
    {
        if (this == &other)
            return (*this);
        _c = other._c;
        return (*this);
    }

    // =============================================================================
    // MEMBERS =====================================================================

    bool
    empty() const
    {
        if (_c.size() == 0)
            return (true);
        return (false);
    }

    size_type 
    size() const
    {
        return (_c.size());
    }

    void 
    push (const value_type& val)
    {
        _c.push_back(val);
    }

    value_type&
    top()
    {
        return (_c.back());
    }

    const value_type& 
    top() const
    {
        return (_c.back());
    }

    void
    pop()
    {
        _c.pop_back();
    }


    template <class T2, class Container2>
    friend bool 
    operator== (const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);

    template <class T2, class Container2>  
    friend bool 
    operator<  (const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);

};


template <class T, class Container>
bool 
operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    if (lhs._c == rhs._c)
        return (true);
    return (false);
}

template <class T, class Container>  
bool 
operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return !(lhs == rhs);
}

template <class T, class Container>  
bool 
operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    if (lhs._c < rhs._c)
        return (true);
    return (false);
}


template <class T, class Container>
bool
operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return !(lhs < rhs);
}


template <class T, class Container>
bool 
operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (rhs < lhs );
}


template <class T, class Container>
bool 
operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return !(lhs < rhs );
}


NAME_SPACE_END
#endif
