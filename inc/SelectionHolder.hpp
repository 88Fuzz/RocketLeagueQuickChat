#ifndef SELECTION_HOLDER_HPP
#define SELECTION_HOLDER_HPP

template <class T> struct SelectionHolder
{
    SelectionHolder(T selected, T deselected):
        selected(selected), deselected(deselected)
    {
    }
    T selected;
    T deselected;
};

#endif
