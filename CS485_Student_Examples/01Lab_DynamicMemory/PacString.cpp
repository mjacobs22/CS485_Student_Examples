#include "PacString.h"
#include <utility>


PacString::PacString()
{
	//std::cout << "Default ctor called.\n";
}

PacString::PacString(const char *pszString)
{
	mpszData = new char[strlen(pszString) + 1];

	for (int i = 0; i < strlen(pszString) + 1; i++)
	{
		mpszData[i] = pszString[i];
	}

	//std::cout << "Overloaded ctor called.\n";
}

PacString::PacString(const PacString &rcData) : PacString(rcData.mpszData)
{
	//std::cout << "CCtor called.\n";
}

PacString::~PacString()
{
	delete[] mpszData;
	//std::cout << "Dtor called.\n";
}

//PacString& PacString::operator=(const PacString &rcData)
//{
//	delete[] mpszData;
//
//	mpszData = new char[strlen(rcData.mpszData) + 1];
//	strcpy_s(mpszData, strlen(rcData.mpszData) + 1, rcData.mpszData);
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
	PacString cNewData = *this + rcData;
	std::swap(cNewData.mpszData, mpszData);

	return *this;
}

PacString PacString::operator+(const PacString &rcData) const
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
	PacString cNewData(pTemp);
	delete[] pTemp;

	return cNewData;
}