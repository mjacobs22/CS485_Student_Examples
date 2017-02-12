#include "PacString.h"
#include <utility>

PacString::PacString ()
{
}

PacString::PacString (const char *pszString)
{
	mpszData = new char[strlen(pszString) + 1];

	for (int i = 0; i <= strlen(pszString) + 1; i++)
	{
		mpszData[i] = pszString[i];
	}

	//delete pszString;
}

PacString::PacString (const PacString &rcData)
{
	mpszData = rcData.mpszData;

	//rcData.~PacString();
}

PacString::~PacString ()
{
	mpszData = nullptr;
	delete mpszData;
}

//PacString& PacString::operator=(const PacString &rcData) //BROKEN
//{
//	delete mpszData;
//	mpszData = rcData.mpszData;
//
//	return *this;
//}

PacString& PacString::operator= (PacString rcData)
{
	using std::swap;
	swap(mpszData, rcData.mpszData);
	rcData.mpszData = nullptr;
	//rcData.~PacString();

	return *this;
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;
	//rcData.~PacString();

	return out;
}

PacString& PacString::operator+=(const PacString &rcData)
{
	PacString *pcNewData = new PacString ();
	*pcNewData = *this + rcData;
	
	//rcData.~PacString();
	return *pcNewData;
}

PacString PacString::operator+(const PacString &rcData) const
{
	char *pTemp = new char[strlen(rcData.mpszData) + strlen(mpszData) + 1];
	int index = 0;
	PacString cNewData;

	for (int i = 0; i < strlen(mpszData); i++)
	{
		pTemp[i] = mpszData[i];
	}

	for (int i = strlen(mpszData); i <= strlen(rcData.mpszData) + strlen(mpszData) + 1; i++)
	{
		pTemp[i] = rcData.mpszData[index++];
	}
	
	cNewData.mpszData = pTemp;

	//rcData.~PacString();
	return cNewData;
}

