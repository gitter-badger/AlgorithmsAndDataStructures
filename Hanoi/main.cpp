#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>

typedef std::pair<int, int> Move;

//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<Move> hanoi(int n, int a, int b, int c)
{
    if (n==1)
    {
        return {{a,b}};
    }

    auto l1 = hanoi(n - 1, a, c, b);
    auto l2 = hanoi(1, a, b, c);
    auto l3 = hanoi(n - 1, c, b, a);

    std::vector<std::pair<int,int>> result;
    result.reserve(l1.size() + l2.size() + l3.size());

    result.insert(result.begin(), l1.begin(), l1.end());
    result.insert(result.begin(), l2.begin(), l2.end());
    result.insert(result.begin(), l3.begin(), l3.end());
    
    return result;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    std::map<int, std::string> towers;
    towers[1] = "A";
    towers[2] = "B";
    towers[3] = "C";

    auto result = hanoi(3, 1, 2, 3);
    std::reverse(result.begin(), result.end());


    for (const auto& moves : result)
    {
        std::cout << std::endl << towers[moves.first] << " -> " << towers[moves.second];
    }

    std::cout << std::endl << "Total number of moves: " << result.size();

    std::cout << std::endl << "\n\n";
    return 0;
}