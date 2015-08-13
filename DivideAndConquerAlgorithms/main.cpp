#include <iostream>
#include <vector>


//==============================================================================================================================================
bool findElement(const std::vector<int>& elements, int key, int start, int end)
{
    int mid = (start + end) / 2;

    if (start > end)
    {
        return false;
    }

    if (elements[mid] == key)
    {
        return true;
    }
    else if (elements[mid] < key)
    {
        findElement(elements, key, mid + 1, end);
    }
    else
    {
        findElement(elements, key, start, mid - 1);
    }
}

//==============================================================================================================================================
int getMin(const std::vector<int>& elements, int start, int end)
{
    if (elements[start] == elements[end])
    {
        return elements[start];
    }

    int mid = (start + end) / 2;
    int a   = getMin(elements, start, mid);
    int b   = getMin(elements, mid + 1, end);

    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


//==============================================================================================================================================
int main()
{
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int start = 0;
    int end   = elements.size() - 1;

    std::cout << std::endl << getMin(elements, start, end);
    std::cout << std::endl << findElement(elements, 10, start, end);

    std::cout << std::endl << "\n\n";
    return 0;
}