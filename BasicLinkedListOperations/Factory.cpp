#include "Factory.h"

namespace factory
{

//==============================================================================================================================================================
LinkedList create(__int64 n)
{
    LinkedList result;

    while(n)
    {
        int d = n % 10;
        result.addFront(d);
        n /= 10;
    }

    return result;
}

//=============================================================================
LinkedList create(const std::vector<int>& elements)
{
    LinkedList result;

    for(auto e : elements)
    {
        result.addBack(e);
    }

    return result;
}

//=============================================================================
LinkedList create(int n)
{
    LinkedList result;

    for(int i = 0; i < n; i++)
    {
        result.addBack(i);
    }

    return result;
}

//==============================================================================================================================================
LinkedList create(const LinkedList& list)
{
    LinkedList result;
    LinkedList::Node* n = list.getHead();

    while(n)
    {
        result.addBack(n->data);
        n = n->next;
    }


    return result;
}

} // namespace factory
