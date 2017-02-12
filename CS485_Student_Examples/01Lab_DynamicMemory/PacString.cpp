#include "PacString.h"
#include <utility>

PacString::PacString ()
{
}

PacString::PacString (const char *pszString)
{
	*mpszData = *pszString; //This throws an exception.
	//mpszData = pszString; //This won't let me assign because mpszData isn't const.
}

PacString::PacString (const PacString &rcData)
{
	mpszData = rcData.mpszData;
}

PacString::~PacString ()
{
	mpszData = nullptr;
	delete mpszData;
}

PacString& PacString::operator=(const PacString &rcData)
{
	delete mpszData;
	mpszData = rcData.mpszData;

	return *this;
}

//PacString& PacString::operator= (PacString rcData)
//{
//	using std::swap;
//	swap(mpszData, rcData.mpszData);
//	rcData.mpszData = nullptr; //?
//
//	return *this;
//}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}

//PacString& operator+=(const PacString &rcData)
//{
//
//}

//PacString operator+(const PacString &rcData) const
//{
//
//}

