#pragma once

#include <exception>


namespace exceptions
{

//!-----------------------------------------------------------------------------------
//! \class empty_list
//! \brief Thrown when the linked list has head = nullptr
//!-----------------------------------------------------------------------------------
class empty_list : public std::exception
{
    public:
        virtual const char* what() const override;
};

//!-----------------------------------------------------------------------------------
//! \class out_of_range
//! \brief Thrown when the client asks for a position which is not in range
//!-----------------------------------------------------------------------------------
class out_of_range : public std::exception
{
    public:
        virtual const char* what() const override;
};

} // namespace exceptions