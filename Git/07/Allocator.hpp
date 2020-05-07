#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>
#include <iterator>

template <class T>
class Allocator
{
    public:
        T* allocate(size_t size)
        {
            return static_cast<T*>(operator new(size * sizeof(T)));
        }
        void deallocate(T* data, size_t size)
        {
            operator delete(data, size*sizeof(T));
        }

        template<class... Args>
        void construct(T* data, Args&&... args)
        {
            new(data) T(std::forward<Args>(args)...);
        }
        void destroy(T* data)
        {
            data->~T();
        }
};

#endif
