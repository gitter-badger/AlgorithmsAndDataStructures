#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>

//================================================================================================================================================================================================================================================================
std::vector<std::pair<int, int>> hanoi(int n, int a, int b, int c)
{
    if(n == 1)
    {
        std::vector<std::pair<int, int>> l;
        l.emplace_back(a, b);
        return l;
    }

    auto l1 = hanoi(n - 1, a, c, b);
    auto l2 = hanoi(1, a, b, c);
    auto l3 = hanoi(n - 1, c, b, a);

    std::vector<std::pair<int, int>> result;
    std::copy(l1.begin(), l1.end(), std::back_inserter(result));
    std::copy(l2.begin(), l2.end(), std::back_inserter(result));
    std::copy(l3.begin(), l3.end(), std::back_inserter(result));

    return result;
}

//================================================================================================================================================================================================================================================================
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int n = 3;
    std::map<int, std::string> towers;
    towers[a] = "A";
    towers[b] = "B";
    towers[c] = "C";

    auto moves = hanoi(n, a, b, c);
    for(auto m : moves)
    {
        std::cout << std::endl << towers[m.first] << " -> " << towers[m.second] << "\n";
    }

    return 0;
}