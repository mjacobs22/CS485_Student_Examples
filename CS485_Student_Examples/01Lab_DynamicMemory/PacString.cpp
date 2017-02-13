#include "PacString.h"
#include <utility>

PacString::PacString ()
{
	std::cout << "Ctor called.\n";
}

PacString::PacString (const char *pszString)
{
	mpszData = new char[strlen(pszString) + 1];

	for (int i = 0; i <= strlen(pszString); i++)
	{
		mpszData[i] = pszString[i];
	}

	std::cout << "Overloaded ctor called.\n";
}

PacString::PacString (const PacString &rcData)
{
	mpszData = rcData.mpszData;

	std::cout << "Cctor called.\n";
}

PacString::~PacString ()
{
	mpszData = nullptr;
	delete [] mpszData;
	std::cout << "Dtor called.\n";
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

	return *this;
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}

PacString& PacString::operator+=(const PacString &rcData)
{
	char *pTemp = new char[strlen(rcData.mpszData) + strlen(mpszData) + 1];
	int index = 0;

	for (int i = 0; i < strlen(mpszData); i++)
	{
		pTemp[i] = mpszData[i];
	}

	for (int i = strlen(mpszData); i <= strlen(rcData.mpszData) + strlen(mpszData); i++)
	{
		pTemp[i] = rcData.mpszData[index++];
	}

	mpszData = pTemp;
	
	//PacString cNewData = *this + rcData;
	//std::swap(cNewData.mpszData, mpszData);

	return *this;
}

PacString PacString::operator+(const PacString &rcData) const
{
	char *pTemp = new char[strlen(rcData.mpszData) + strlen(mpszData) + 1];
	int index = 0;
	//PacString cNewData;

	for (int i = 0; i < strlen(mpszData); i++)
	{
		pTemp[i] = mpszData[i];
	}

	for (int i = strlen(mpszData); i <= strlen(rcData.mpszData) + strlen(mpszData); i++)
	{
		pTemp[i] = rcData.mpszData[index++];
	}
	
	PacString cNewData (pTemp);
	//cNewData.mpszData = pTemp;

	delete[] pTemp;
	return cNewData;
}

