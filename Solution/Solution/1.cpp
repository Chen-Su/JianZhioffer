#include <iostream>

using namespace std;

class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	CMyString& operator =(const CMyString& lhs);
	~CMyString(void);

private:
	char *m_pData;
};

CMyString::CMyString(char * pData)
{
}

CMyString::CMyString(const CMyString & str)
{
}

CMyString & CMyString::operator=(const CMyString & lhs)
{
	// TODO: insert return statement here
	if (&lhs == this)
		// 不能用lhs == *this来判断，因为lhs是const.
		return *this;
	
	CMyString strtmp(lhs);
	// swap
	char *ptmp = this->m_pData;
	this->m_pData = strtmp.m_pData;
	strtmp.m_pData = ptmp;

	return *this;
}

CMyString::~CMyString(void)
{
}
