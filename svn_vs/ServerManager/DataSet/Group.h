#pragma once

#ifndef __GROUP_H__
#define __GROUP_H__
#include <Windows.h>
#include <list>
#include "Common.h"//also use in linux

using namespace std;
class CGroup
{
public:
	CGroup() : m_lGroupID(0), m_wGroupNameLen(0)
	{
	}
	
	void SetGroupName(unsigned short wLen,const char* name)
	{
		m_wGroupNameLen = wLen;
		memcpy(m_szGroupName,name,wLen);
	}
	bool AddUser(unsigned long lUserID)
	{
		list<unsigned long>::iterator it = m_oUserList.begin();
		while(it != m_oUserList.end()){
			if(*it == lUserID){//already have this user id
				return false;
			}
			it++;
		}
		m_oUserList.push_back(lUserID);
		return true;
	}
	bool DelUser(unsigned long lUserID)
	{
		list<unsigned long>::iterator it = m_oUserList.begin();
		while(it != m_oUserList.end()){
			if(*it == lUserID){
				m_oUserList.erase(it);//find
				return true;
			}
			it++;
		}
		return false;
	}
	char* GetGroupName()
	{
		return m_szGroupName;		
	}
private:
	unsigned long m_lGroupID;
	list<unsigned long> m_oUserList;//the user id in group list
	unsigned short m_wGroupNameLen;
	char m_szGroupName[DEF_GROUP_NAME_LEN];
};










#endif//__GROUP_H__