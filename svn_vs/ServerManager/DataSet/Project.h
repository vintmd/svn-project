#pragma once

#ifndef __PRO_H__
#define __PRO_H__
#include <Windows.h>
#include <list>
#include "Common.h"
using namespace std;
class CProject
{
public:
	CProject() : m_lProjectID(0), m_wProNameLen(0), m_lCreateTime(0)
	{
	}
	bool AddUser(unsigned long lUserID,unsigned long lPower)
	{
		//将lUserID存储在低位4个字节，
		INT64 i64Value = (((INT64)lPower) << 32) + lUserID;
		list<INT64>::iterator it = m_oUserList.begin();
		while(it != m_oUserList.end()){
			if( (unsigned long(*it)) == lUserID){
				//already have use so only set power
				*it = i64Value;
				return true;
			}
			it++;
		}
		m_oUserList.push_back(i64Value);
		return true;
	}
	bool DelUser(unsigned long lUserID)
	{
		list<INT64>::iterator it = m_oUserList.begin();
		while(it != m_oUserList.end()){
			if((unsigned long)(*it) == lUserID){
				m_oUserList.erase(it);//find
				return true;
			}
			it++;
		}
		return false;
	}
	void SetProName(unsigned short wLen,const char* name)
	{
		m_wProNameLen = wLen;
		memcpy(m_szProName,name,wLen);
	}
	char* GetProName()
	{
		return m_szProName;
	}
	unsigned long GetProID()
	{
		return m_lProjectID;
	}
private:
	unsigned long m_lProjectID;
	unsigned long m_lCreateTime;
	//use int64 because can save one user id and one power enum 
	list<INT64> m_oUserList;
	unsigned short m_wProNameLen;
	char m_szProName[DEF_MAX_PROJECT_LEN];
};


#endif//__PRO_H__