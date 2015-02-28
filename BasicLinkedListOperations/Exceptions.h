#pragma once

#include <exception>


namespace exceptions
{

class empty_list : public std::exception
{
    public:
        virtual const char* what() const override;
};

class out_of_range : public std::exception
{
    public:
        virtual const char* what() const override;
};

}