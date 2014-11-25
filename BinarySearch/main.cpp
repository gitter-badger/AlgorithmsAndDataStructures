#include <iostream>
#include <vector>


bool binary_search(const std::vector<int>& elements, int element, int low, int high)
{
    if(low > high)
    {
        return false;
    }

    int mid = (low + high) / 2;

    if(elements[mid] == element)
    {
        return true;
    }

    if(element < elements[mid])
    {
        return binary_search(elements, element, low, mid - 1);
    }
    else
    {
        return binary_search(elements, element, mid + 1, high);
    }
}

bool binary_search(const std::vector<int>& elements, int element)
{
    return binary_search(elements, element, 0, elements.size());
}


int main()
{
    std::vector<int> elements {1, 2, 3, 4, 5, 6};
    std::cout << std::endl << binary_search(elements, -1);
    return 0;
}