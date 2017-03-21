#ifndef VECTOR_WRAPPER_HPP
#define VECTOR_WRAPPER_HPP

#include <vector>

/*
 * Wrapper around the vector collection so that accessing indexes
 * < 0 or > vector.size will wrap around the collection.
 */
template <class T> class VectorWrapper
{
public:
    VectorWrapper(std::vector<T> collection): collection(collection)
    {
    }

    /*
     * If the ipnut is < 0 or > vector.size, the reutrned object
     * will be looped around the collection.
     */
    T get(int index) const
    {
        if(index < 0)
        {
            while(index < 0)
                index += collection.size();
        }
        else if (index > collection.size())
        {
            while(index > collection.size())
                index -= collection.size();
        }
    
        return collection[index];
    }

    int size() const
    {
        return collection.size();
    }

    std::vector<T>& getCollection()
    {
        return collection;
    }

private:
    std::vector<T> collection;
};

#endif
