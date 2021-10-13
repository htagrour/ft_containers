#ifndef STACK_HPP
#define STACK_HPP
#include <deque>
namespace ft
{
    template<typename T, typename _Container = std::deque<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef _Container container_type;
            typedef size_t size_type;

            explicit stack(const container_type &ctnr = container_type()): c(ctnr){}
            bool empty() const { return(c.empty());}
            size_type size() const { return (c.size());}
            value_type& top() { return ( c.back());}
            const value_type& top() const {return ( c.back());}
            void push (const value_type& val) { c.push_back(val);}
            void pop() { c.pop_back();}

            template <class _T, class Container>
                friend bool operator== (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
            template <class _T, class Container>
                friend bool operator!= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
            template <class _T, class Container>
                friend bool operator<  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
            template <class _T, class Container>
                friend bool operator<= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
            template <class _T, class Container>
                friend bool operator>  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
            template <class _T, class Container>
                friend bool operator>= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs);
                
        protected:
            container_type c;
    };

    template <class _T, class Container>
        bool operator== (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  == rhs.c);}
    template <class _T, class Container>
        bool operator!= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  != rhs.c);}
    template <class _T, class Container>
        bool operator<  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  < rhs.c);}
    template <class _T, class Container>
        bool operator<= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  <= rhs.c);}
    template <class _T, class Container>
        bool operator>  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  > rhs.c);}
    template <class _T, class Container>
        bool operator>= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs.c  >= rhs.c);}

}
#endif