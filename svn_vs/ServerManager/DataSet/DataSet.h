//数据管理类 内存池 解决频繁创建销毁数据对象
#pragma once
#ifndef __DATASET_H__
#define __DATASET_H__
#include <deque>
#include "User.h"
#include "Group.h"
#include "Project.h"
#include "Common.h"


class CDataSet
{
public:
	CDataSet();
	~CDataSet();
	//if only use the list do not need Init and Destory Data set 
	bool InitDataSet(int iMaxCount);
	void DestroyDataSet();
	
	//add 
	bool AddUser(unsigned long lUserID, unsigned short wPasswordLen,
		const char* pPassword);
	bool AddGroup(const char* pGroupName);
	bool AddProject(const char* pProName);
	//delete
	bool DelUser(unsigned long lUserID);
	bool DelGroup(const char* pGroupName);
	bool DelProject(const char* pProName);
	//change
	bool ModifyUserPass(unsigned long lUserID, unsigned short wPasswordLen,
		const char* pPassword);
	bool ModifyGroup(const char* pGroupName, unsigned long lOprTyp);//watch ENUM_GROUP_OPR_TYPE
	bool SetUserPower(unsigned long lProID, unsigned long lUserID,
		unsigned long lUserPower);//watch ENUM_POWER_TYPE
	bool SetGroupPower(unsigned long lProID, unsigned long lGroupID,
		unsigned long lGroupPower);
	//for UI to get the numbers in which set to show 
	//used to be void GetUserList(list<unsigned long>& userList);//user id
	//传入NULL代表取第一个，返回0代表无
	unsigned long GetNextUser(unsigned long lUserID);
	const char* GetNextGroup(const char* pGroupName);
	const char* GetNextProject(const char* pProName);
private:
	//use the list to manage user group project
	//存指针没有考虑复用问题 需要频繁的创建和销毁
	//可以将其用作索引list get class from pool
	list<CUser*> m_listUser;
	list<CGroup*> m_listGroup;
	list<CProject*> m_listPro;
	int count;//the num of pool
	//the class pool 
	CUser* m_pIdleUser;
	std::deque<int> m_indexUser;
	CGroup* m_pIdleGroup;
	std::deque<int> m_indexGroup;
	CProject* m_pIdleProject;
	std::deque<int> m_indexProject;

};



 #endif//__DATASET_H__