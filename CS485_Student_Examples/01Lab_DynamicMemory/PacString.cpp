#include "PacString.h"
#include <utility>

PacString& PacString::operator=(const PacString &rcData)
{
	//Actually points back to object in main, don't want to disturb that object

	delete mpszData;
	mpszData = rcData.mpszData;
	//rcData.mpszData = nullptr;

	return *this;
}

//PacString& PacString::operator= (PacString cData)
//{
//	using std::swap;
//	swap(mpszData, cData.mpszData);
//
//	return *this;
//}

