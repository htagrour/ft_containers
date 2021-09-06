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

            explicit stack(const container_type &ctnr = container_type()): _container(ctnr){}
            bool empty() const { return(_container.empty());}
            size_type size() const { return (_container.size());}
            value_type& top() { return ( _container.back());}
            const value_type& top() const {return ( _container.back());}
            void push (const value_type& val) { _container.push_back(val);}
            void pop() { _container.pop_back();}

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
                
        private:
            container_type _container;
    };

    template <class _T, class Container>
        bool operator== (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  == rhs._container);}
    template <class _T, class Container>
        bool operator!= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  != rhs._container);}
    template <class _T, class Container>
        bool operator<  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  < rhs._container);}
    template <class _T, class Container>
        bool operator<= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  <= rhs._container);}
    template <class _T, class Container>
        bool operator>  (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  > rhs._container);}
    template <class _T, class Container>
        bool operator>= (const stack<_T,Container>& lhs, const stack<_T,Container>& rhs)
        {return (lhs._container  >= rhs._container);}

}
#endif