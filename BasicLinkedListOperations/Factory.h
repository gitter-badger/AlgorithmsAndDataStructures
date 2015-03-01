#pragma once

#include "LinkedList.h"

#include <vector>


namespace factory
{

//!-----------------------------------------------------------------------------------
//! \brief     Creates a single linked list from a very big number
//! \note      n = 124331 => L = 1->2->4->3->3->1->NULL
//! \param[in] n The number to represent the linked list
//! \returns   The generated linked list
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList create(__int64 n);

//!-----------------------------------------------------------------------------------
//! \brief     Creates a SLL from a vector
//! \note	   nothing
//! \param[in] elements
//! \returns   LinkedList Created linked list
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList create(const std::vector<int>& elements);


//!-----------------------------------------------------------------------------------
//! \brief
//! \param[in] n
//! \returns   LinkedList
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList create(int n);

//!-----------------------------------------------------------------------------------
//! \brief
//! \param[in] list
//! \returns   nothing
//! \throws    no
//!-----------------------------------------------------------------------------------
LinkedList create(const LinkedList& list);

} // namespace factory