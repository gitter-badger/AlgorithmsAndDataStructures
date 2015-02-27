#pragma once

#include "../BasicLinkedListOperations/LinkedList.h"


namespace utils
{
bool areEqual(LinkedList& list, const std::vector<int>& vector);
bool isContained(LinkedList& list, const std::vector<int>& vector);
}