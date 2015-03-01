#pragma once

//! \file Macros.h
//! \brief Here reside all macro definitions.
//! They are used to make things easier, like declaring smart pointers for classes

#include <memory>


//! \brief Easy way to create pointer classes for a certain class
//!
//! \code{.cpp}
//!		FORWARD_CLASS_DECLARATION(Person) // anywhere in your file
//!		PersonUptr p = std::make_unique<Person>(); // can safely use
//!		PersonSptr p = std::make_shared<Person>();
//! \endcode
//!
#define FORWARD_CLASS_DECLARATION(className)            \
	class className;						            \
	typedef className*                 ##classNamePtr;  \
	typedef std::shared_ptr<className> ##classNameSPtr; \
	typedef std::unique_ptr<className> ##classNameUPtr; \
	typedef std::weak_ptr<className>   ##classNameWPtr;


