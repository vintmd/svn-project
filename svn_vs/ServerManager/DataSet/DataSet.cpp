#include "DataSet.h"

CDataSet :: CDataSet(){
	count = 0;
}
CDataSet :: ~CDataSet(){
	DestroyDataSet();
}
//if only use the list do not need Init and Destory Data set 
bool CDataSet :: InitDataSet(int iMaxCount){
	//when init first destroy 
	DestroyDataSet();
	int count = iMaxCount;
	//create idle arr
	m_pIdleUser = new CUser[count];	
	m_pIdleGroup  = new CGroup[count];
	m_pIdleProject = new CProject[count];
	//fill the queue of idle
	for( long i = 0; i < count; i++){
		m_indexUser.push_back(i);
		m_indexGroup.push_back(i);
		m_indexProject.push_back(i);
	}
	return true;
}
void CDataSet :: DestroyDataSet(){
	//clear list
	m_listUser.clear();
	m_listGroup.clear();
	m_listPro.clear();
	//memery return 
	if(m_pIdleUser){
		delete[] m_pIdleUser;
		m_pIdleUser = NULL;
	}
	if(m_pIdleGroup){
		delete[] m_pIdleGroup;
		m_pIdleGroup = NULL;
	}
	if(m_pIdleProject){
		delete[] m_pIdleProject;
		m_pIdleProject = NULL;
	}
	//clear idle list
	m_indexUser.clear();
	m_indexGroup.clear();
	m_indexProject.clear();
	return ;
}
//add 
bool CDataSet :: AddUser(unsigned long lUserID, unsigned short wPasswordLen,
const char* pPassword){
	//获取空闲用户内存池的结点索引
	int index = m_indexUser.front();		
	m_indexUser.pop_front();
	//set user info
	m_pIdleUser[index].SetUser(lUserID);
	m_pIdleUser[index].SetPassword(wPasswordLen,pPassword);
	//add to user list. if failed return the index to the memery pool
	list<CUser*> :: iterator it =  m_listUser.begin();
	while( it != m_listUser.end() ){
		if( (*it)->GetUserID() == lUserID ){
			//the userid was already have been inserted into user list
			//return the index to pool
			m_indexUser.push_front(index);
			return false;
		}
		it++;
	}
	//add the user into user list
	m_listUser.push_back(&m_pIdleUser[index]);
	return true;
}
bool CDataSet :: AddGroup(const char* pGroupName){
	int index  = m_indexGroup.front();
	m_indexGroup.pop_front();
	m_pIdleGroup[index].SetGroupName(strlen(pGroupName) + 1, pGroupName);
	list<CGroup*> :: iterator it = m_listGroup.begin();
	while( it != m_listGroup.end() ){
		if( 0 == strcmp( (*it)->GetGroupName(),pGroupName )){
			//find the group	
			m_indexGroup.push_front(index);
			return false;
		}
		it++;
	}
	m_listGroup.push_back(&m_pIdleGroup[index]);
	return true;

}
bool CDataSet :: AddProject(const char* pProName){
	int index  = m_indexProject.front();
	m_indexProject.pop_front();
	m_pIdleProject[index].SetProName(strlen(pProName) + 1, pProName);
	list<CProject*> :: iterator it = m_listPro.begin();
	while( it != m_listPro.end() ){
		if( 0 == strcmp( (*it)->GetProName(),pProName )){
			//find the group	
			m_indexProject.push_front(index);
			return false;
		}
		it++;
	}
	m_listPro.push_back(&m_pIdleProject[index]);
	return true;
	
}
//delete 
bool CDataSet :: DelUser(unsigned long lUserID){
	list<CUser*> :: iterator it =  m_listUser.begin();
	while( it != m_listUser.end() ){
		if( (*it)->GetUserID() == lUserID ){
			//count index which need to be return to the pool
			int index =  ((*it) - m_pIdleUser) % sizeof(CUser);
			//return the index to pool
			m_indexUser.push_front(index);
			return true;
		}
		it++;
	}	
	return false;

}
bool CDataSet :: DelGroup(const char* pGroupName){
	list<CGroup*> :: iterator it =  m_listGroup.begin();
	while( it != m_listGroup.end() ){
		if( (*it)->GetGroupName() == pGroupName ){
			//count index which need to be return to the pool
			int index =  ((*it) - m_pIdleGroup) % sizeof(CGroup);
			//return the index to pool
			m_indexGroup.push_front(index);
			return true;
		}
		it++;
	}	
	return false;	
}
bool CDataSet :: DelProject(const char* pProName){
	list<CProject*> :: iterator it =  m_listPro.begin();
	while( it != m_listPro.end() ){
		if( (*it)->GetProName() == pProName ){
			//count index which need to be return to the pool
			int index =  ((*it) - m_pIdleProject) % sizeof(CProject);
			//return the index to pool
			m_indexProject.push_front(index);
			return true;
		}
		it++;
	}	
	return false;
}

//change
bool CDataSet :: ModifyUserPass(unsigned long lUserID, unsigned short wPasswordLen,
	const char* pPassword){
	list<CUser*> :: iterator it =  m_listUser.begin();
	while( it != m_listUser.end() ){
		if( (*it)->GetUserID() == lUserID ){
			//find and modify password
			(*it)->SetPassword(wPasswordLen,pPassword);
			return true;
		}
		it++;
	}
	return false;

}
bool CDataSet :: ModifyGroup(const char* pGroupName, unsigned long lOprTyp){//watch ENUM_GROUP_OPR_TYPE
	bool flag;
	if(lOprTyp == enum_group_opr_add){//add group
		flag = AddGroup(pGroupName);
	}else{//enum_group_opr_del
		flag = DelGroup(pGroupName);
	}
	if(flag)
		return true;
	return false;
}
bool CDataSet :: SetUserPower(unsigned long lProID, unsigned long lUserID,
	unsigned long lUserPower){//watch ENUM_POWER_TYPE
	//according proid find the usrlist in this project, then set power
	list<CProject*> :: iterator it = m_listPro.begin();
	while( it != m_listPro.end() ){
		if( (*it)->GetProID == lProID){
			//find the group	
			(*it)->AddUser(lUserID, lUserPower);
			return true;
		}
		it++;
	}
	return false;
}
bool CDataSet :: SetGroupPower(unsigned long lProID, unsigned long lGroupID,
	unsigned long lGroupPower){
	list<CProject*> :: iterator it = m_listPro.begin();
	while( it != m_listPro.end() ){
		if( (*it)->GetProID == lProID){
			//find the project	
			(*it)->AddUser(lGroupID, lGroupPower);
			return true;
		}
		it++;
	}
	return false;
}
//get next
//传入NULL代表取第一个，返回0代表无
unsigned long CDataSet :: GetNextUser(unsigned long lUserID){
	list<CUser*> :: iterator it =  m_listUser.begin();
	while( it != m_listUser.end() ){
		if( (*it)->GetUserID() == lUserID ){
			it++;
			if((*it) != NULL)
				return (*it)->GetUserID();
			else
				return 0;
		}
		it++;
	}
	return 0;
}
const char* CDataSet :: GetNextGroup(const char* pGroupName){
	list<CGroup*> :: iterator it =  m_listGroup.begin();
	while( it != m_listGroup.end() ){
		if(pGroupName == NULL){
			it++;
			if((*it) != NULL)
				return (*it)->GetGroupName();
			else
				return NULL;
		}else if( 0 == strcmp((*it)->GetGroupName(), pGroupName) ){
			it++;
			if((*it) != NULL)
				return (*it)->GetGroupName();
			else
				return NULL;
		}
		it++;
	}	
	return NULL;
}
const char* CDataSet :: GetNextProject(const char* pProName){
	list<CProject*> :: iterator it = m_listPro.begin();
	while( it != m_listPro.end() ){
		if( pProName == NULL){
			it++;
			if((*it) != NULL)
				return (*it)->GetProName();
			else
				return NULL;
		}else if( 0 == strcmp( (*it)->GetProName(),pProName )){
				it++;
				if((*it) != NULL)
					return (*it)->GetProName();
				else
					return NULL;
		}
		it++;
	}
	return NULL;
}