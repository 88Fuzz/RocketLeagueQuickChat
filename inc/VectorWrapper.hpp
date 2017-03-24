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
        unsigned int unsignedIndex = index;
        if(index < 0)
        {
            while(index < 0)
                index += collection.size();
        }
        else if (unsignedIndex >= collection.size())
        {
            while(unsignedIndex >= collection.size())
                unsignedIndex -= collection.size();
            index = unsignedIndex;
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
