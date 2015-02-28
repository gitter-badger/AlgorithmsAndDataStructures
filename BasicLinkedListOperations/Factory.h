#pragma once

#include "LinkedList.h"

#include <vector>


namespace factory
{

LinkedList create(__int64 n);
LinkedList create(const std::vector<int>& elements);
LinkedList create(int n);
LinkedList create(const LinkedList& list);

} // namespace factory