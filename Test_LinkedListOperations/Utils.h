#pragma once

#include "../BasicLinkedListOperations/LinkedList.h"

#include <string>


namespace utils
{

bool areEqual(LinkedList& list, const std::vector<int>& vector);
bool isContained(LinkedList& list, const std::vector<int>& vector);
std::string convertToString(const LinkedList& l1);

}