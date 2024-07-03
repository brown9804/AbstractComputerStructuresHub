#include "header.h"

using namespace std;

template <typename D>
class Element
{
public:
    Element()
    {
        this->valid = false;
    };

    Element(D d)
    {
        this->data = d;
        this->valid = true;
    };

    Element(const Element &orig)
    {
        this->data = orig.data;
        this->valid = orig.valid;
    };

    ~Element(){

    };

    D get()
    {
        return this->data;
    };

    void set(D d)
    {
        this->data = d;
        this->valid = true;
    };

    bool operator==(D rhs)
    {
        return this->data == rhs.data;
    };

    D operator=(D rhs)
    {
        this->data = rhs.data;
        this->valid = rhs.valid;
        return *this;

    };


    bool isValid()
    {
        return valid;
    };

private:
    D data;
    bool valid;
};
