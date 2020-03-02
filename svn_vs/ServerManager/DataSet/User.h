#pragma once

#ifndef __USER_H__
#define __USER_H__
#include <Windows.h>
#include "Common.h"//also use in linux
class CUser
{
public:
	CUser() : m_lUserID(0), m_wPasswordLen(0)
	{
	}
	void SetUser(unsigned long id)
	{
		m_lUserID = id;
	}
	void SetPassword(unsigned short wLen,const char* password)
	{
		m_wPasswordLen = wLen;
		memcpy(m_szPassword,password,wLen);
	}
	unsigned long GetUserID()
	{
		return m_lUserID;
	}
private:
	unsigned long m_lUserID;
	unsigned short m_wPasswordLen;
	char m_szPassword[DEF_MAX_PASS_LEN];
};










#endif//__USER_H__