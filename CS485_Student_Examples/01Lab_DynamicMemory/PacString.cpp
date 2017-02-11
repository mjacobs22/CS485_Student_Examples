#include "PacString.h"
#include <utility>

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
//
//	return *this;
//}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{

}

//PacString& operator+=(const PacString &rcData)
//{
//
//}

//PacString operator+(const PacString &rcData) const
//{
//
//}

