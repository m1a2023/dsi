#pragma once

#include <string>

namespace dsi {
template <typename T> class IDataStructure {
public:
    //constructor and destructor
    IDataStructure() { }
    ~IDataStructure() { }

    //core methods
    virtual T               pop()           = 0;

    virtual void            push(T item)    = 0;

    virtual T               peek()          = 0;

    virtual int             size()          = 0;
    virtual void            clear()         = 0;
    virtual bool            is_empty()      = 0;

    virtual std::string     to_string()     = 0;
};
};
