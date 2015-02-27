#include "Utils.h"

#include <string>
#include <CppUnitTestLogger.h>


//==============================================================================================================================================================
bool utils::areEqual(LinkedList& list, const std::vector<int>& vector)
{
    std::vector<int> listAsVector = list;

    if(listAsVector.size() != vector.size())
    {
        return false;
    }

    auto itList   = listAsVector.begin();
    auto itVector = vector.begin();

    while(itList != listAsVector.end())
    {
        if((*itList) != (*itVector))
        {
            return false;
        }

        itList++;
        itVector++;
    }

    return true;
}

//==============================================================================================================================================================
bool utils::isContained(LinkedList& list, const std::vector<int>& vector)
{
    bool contained = true;

    std::vector<int> elements = list;
    for(auto v : vector)
    {
        auto foundIt = std::find(elements.begin(), elements.end(), v);
        if(foundIt == elements.end())
        {
            contained = false;
        }
    }

    return contained;
}

