#pragma once

#ifndef __C2S_H__
#define __C2S_H__

//protocol client to server
#define DEF_CS_START  (2000)
#define DEF_CS_LOGIN_RQ    (DEF_CS_START + 1)
#define DEF_CS_LOGIN_RS    (DEF_CS_START + 2)

#define DEF_CS_GET_PRO_LIST_RQ (DEF_CS_START + 3)
#define DEF_CS_GET_PRO_LIST_RS (DEF_CS_START + 4)

#define DEF_CS_ADD_FILE_RQ    (DEF_CS_START + 5)
#define DEF_CS_ADD_FILE_RS    (DEF_CS_START + 6)

#define DEF_CS_ADD_FOLDER_RQ    (DEF_CS_START + 7)
#define DEF_CS_ADD_FOLDER_RS   (DEF_CS_START + 8)

#define DEF_CS_DEL_FILE_RQ    (DEF_CS_START + 9)
#define DEF_CS_DEL_FILE_RS    (DEF_CS_START + 10)

#define DEF_CS_DEL_FOLDER_RQ    (DEF_CS_START + 11)
#define DEF_CS_DEL_FOLDER_RS   (DEF_CS_START + 12)

#define DEF_CS_COMMIT_PRO_RQ (DEF_CS_START + 13)
#define DEF_CS_COMMIT_PRO_RS (DEF_CS_START + 14)

#define DEF_CS_LOCK_PRO_RQ (DEF_CS_START + 15)
#define DEF_CS_LOCK_PRO_RS (DEF_CS_START + 16)

#define DEF_CS_UNLOCK_PRO_RQ (DEF_CS_START + 17)
#define DEF_CS_UNLOCK_PRO_RS (DEF_CS_START + 18)

//important thing is that how to find out change 
#define DEF_CS_UPDATE_PRO_RQ (DEF_CS_START + 19)
#define DEF_CS_UPDATE_PRO_RS (DEF_CS_START + 20)

#define DEF_CS_UPDATE_PRO_RQ (DEF_CS_START + 19)
#define DEF_CS_UPDATE_PRO_RS (DEF_CS_START + 20)

#define DEF_CS_HISTORY_RQ (DEF_CS_START + 21)
#define DEF_CS_HISTORY_RS (DEF_CS_START + 22)

#define DEF_CS_COMPARE_RQ (DEF_CS_START + 23)
#define DEF_CS_COMPARE_RS (DEF_CS_START + 24)

#define DEF_CS_ROLLBACK_RQ (DEF_CS_START + 25)
#define DEF_CS_ROLLBACK_RS (DEF_CS_START + 26)

#define DEF_CS_SEARCH_NAME_RQ (DEF_CS_START + 27)
#define DEF_CS_SEARCH_NAME_RS (DEF_CS_START + 28)

#define DEF_CS_SEARCH_INFO_RQ (DEF_CS_START + 29)
#define DEF_CS_SEARCH_INFO_RS (DEF_CS_START + 30)

#define DEF_CS_LOGOUT_RQ (DEF_CS_START + 31)
#define DEF_CS_LOGOUT_RS (DEF_CS_START + 32)

//base protocol (package)
struct STRU_PROTOCOL_BASE{
public:
	STRU_PROTOCOL_BASE(int iType){
		m_iType = iType;
	}
	//put the package content into the buf
	virtual long Serialize(char* pBuf, long lBufLen) = 0;
	//put the buf content into the package
	virtual bool UnSerialize(const char* pBuf, long lBufLen) = 0;
protected:
	int m_iType;//the protocol type 
};
//constant define
#define DEF_MAX_PASS_LEN     (15)
#define DEF_MAX_PATH_LEN     (100)
#define DEF_MAX_FILE_COUNT   (10)

//login protocol 
struct STRU_LOGIN_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_LOGIN_RQ() : STRU_PROTOCOL_BASE(DEF_CS_LOGIN_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name  must be carry 
	unsigned short m_wPasswordLen;
	char m_szPassword[DEF_MAX_PASS_LEN];
};
struct STRU_LOGIN_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_LOGIN_RS() : STRU_PROTOCOL_BASE(DEF_CS_LOGIN_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
	unsigned short m_wResult; //watch the ENUM_RS_RES
	unsigned long m_ulVerifyCode;//替代密码做身份验证 服务器向客户端提供
	unsigned long m_ulSeqNum;//序列数由客户端生成向服务器发送，记录客户端对应操作请求
};

//get project list protocol
//but the response can be file or dir 
//so define the struct STRU_FILE_ITEM to use for two ways
struct STRU_GET_PRO_LIST_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_GET_PRO_LIST_RQ() : STRU_PROTOCOL_BASE(DEF_CS_GET_PRO_LIST_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 																														
	unsigned long m_ulVerifyCode;//use the login verfiycode 
	unsigned short m_wPathLen;
	char m_szPath[DEF_MAX_PATH_LEN];//can be file or dir
};
//so define the struct STRU_FILE_ITEM to use for two ways dir or file
//get the info from the server
struct STRU_FILE_ITEM {
public:
	static long MIN_LEN;
	STRU_FILE_ITEM();
	//防止隔代管理父管理子而不是爷管理子
	virtual long Serialize(char*& pBuf, long& lBufLen);
	virtual bool UnSerialize(const char*& pBuf, long& lBufLen);
public:
	unsigned short m_wFileType; //watch ENUM_FILE_TYPE
	unsigned long m_ulFileSize;
	unsigned long m_ulUserID;
	unsigned long m_ulTransTime;
	unsigned short m_wFileLen;//use for both file or dir
	char m_szFile[DEF_MAX_PATH_LEN];
};
struct STRU_GET_PRO_LIST_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_GET_PRO_LIST_RS() : STRU_PROTOCOL_BASE(DEF_CS_GET_PRO_LIST_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
	unsigned long m_ulSeqNum;//客户端发送的操作请求是哪一个
	unsigned short m_wItemCount;
	STRU_FILE_ITEM m_oFileItem[DEF_MAX_FILE_COUNT];
};















#define DEF_C2S_PROTOCOL_COUNT (100)





#endif//__C2S_H__