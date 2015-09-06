#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stack>

//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
std::string normalizePath(const std::string& path)
{
    std::stack<std::string> tempPath;
    auto tokens = split(path, '/');

    for (auto t : tokens)
    {
        if (t != "..")
        {
            tempPath.push(t);
        }
        else
        {
            tempPath.pop();
        }
    }

    std::stack<std::string> normalizedPathStack;
    while (!tempPath.empty())
    {
        if (tempPath.top() != ".")
        {
            normalizedPathStack.push(tempPath.top());
        }

        tempPath.pop();
    }

    std::string finalPath;
    while (!normalizedPathStack.empty())
    {
        finalPath += normalizedPathStack.top() + "/";
        normalizedPathStack.pop();
    }

    return finalPath;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    std::string path = "/home/user/etc/../../release/debug/win32/../../../here/";

    std::cout << std::endl << "Initial: " << path;
    std::cout << std::endl << "Normalized: " << normalizePath(path);

    std::cout << std::endl << "\n\n";
    return 0;
}