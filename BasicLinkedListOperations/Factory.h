#pragma once

#include "LinkedList.h"

#include <vector>


namespace factory
{

LinkedList createFromNumber(__int64 n);
LinkedList createFromVector(const std::vector<int>& elements);

} // namespace factory