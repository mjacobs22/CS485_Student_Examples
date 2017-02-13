//***************************************************************************
// File name:  main.cpp
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************

#define MEM_DEBUG
#include "mem_debug.h"
//#include "vld.h"

#include <iostream>
#include "PacString.h"

int main ()
{
_CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  PacString s1 = "Hello!";

  std::cout << "s1: " << s1 << std::endl;

  PacString s2 ("World");
  std::cout << "s2: " << s2 << std::endl;

  PacString s3;

  s3 = s1 + s2;

  std::cout << "s3: " << s3 << std::endl;

  s3 += (s3 + "!!");

  std::cout << "s3: " << s3 << std::endl;

  // TODO:
	// dynamically allocate the PacString object using
	// pcDynString.
	// Assign "CS485" to pcDynString.
	// Display pcDynString.
	// concatenate " is the best!" on to
	// pcDynString
	// Display pcDynString.
	// deallocate the object pcDynString 

  PacString *pcDynString = new PacString ("CS485 ");
	std::cout << *pcDynString << std::endl;

	*pcDynString = *pcDynString + "is the best!";
	std::cout << *pcDynString << std::endl;
	delete [] pcDynString;

  return EXIT_SUCCESS;
}


