#pragma once

#ifndef __SM2S_H__
#define __SM2S_H__
#include "Common.h"
//protocol server manager to the server 
#define DEF_SMS_START (1000)
//have the request and answer
#define DEF_ADD_USER_RQ  (DEF_SMS_START + 1)
#define DEF_ADD_USER_RS  (DEF_SMS_START + 2)

#define DEF_DEL_USER_RQ  (DEF_SMS_START + 3)
#define DEF_DEL_USER_RS  (DEF_SMS_START + 4)

#define DEF_ADD_GROUP_RQ (DEF_SMS_START + 5)
#define DEF_ADD_GROUP_RS (DEF_SMS_START + 6)

#define DEF_DEL_GROUP_RQ (DEF_SMS_START + 7)
#define DEF_DEL_GROUP_RS (DEF_SMS_START + 8)

#define DEF_ADD_PRO_RQ   (DEF_SMS_START + 9)
#define DEF_ADD_PRO_RS   (DEF_SMS_START + 10)

#define DEF_DEL_PRO_RQ   (DEF_SMS_START + 11)
#define DEF_DEL_PRO_RS   (DEF_SMS_START + 12)

#define DEF_JOIN_GROUP_RQ (DEF_SMS_START + 13)
#define DEF_JOIN_GROUP_RS (DEF_SMS_START + 14)

#define DEF_LEAVE_GROUP_RQ (DEF_SMS_START + 15)
#define DEF_LEAVE_GROUP_RS (DEF_SMS_START + 16)

#define DEF_SET_POWER_RQ   (DEF_SMS_START + 17)
#define DEF_SET_POWER_RS   (DEF_SMS_START + 18)
//the server manager sock keep alive package
#define DEF_ALIVE_RQ	   (DEF_SMS_START + 19)
#define DEF_ALIVE_RS       (DEF_SMS_START + 20)


//base protocol (package) 利用观察者模式？
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
//add user protocol   SM and server in same mechina do not need to verfaiy
struct STRU_ADD_USER_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_USER_RQ() : STRU_PROTOCOL_BASE(DEF_ADD_USER_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
	unsigned short m_wPasswordLen;
	char m_szPassword[DEF_MAX_PASS_LEN];
};
struct STRU_ADD_USER_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_USER_RS() : STRU_PROTOCOL_BASE(DEF_ADD_USER_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
	unsigned short m_wResult; //watch the ENUM_RS_RES
};

//delete user protocol
struct STRU_DEL_USER_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_USER_RQ() : STRU_PROTOCOL_BASE(DEF_DEL_USER_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
};
struct STRU_DEL_USER_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_USER_RS() : STRU_PROTOCOL_BASE(DEF_DEL_USER_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;//user name 
	unsigned short m_wResult; //watch the ENUM_RS_RES
};

//add group protocol
struct STRU_ADD_GROUP_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_GROUP_RQ() : STRU_PROTOCOL_BASE(DEF_ADD_GROUP_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];
};
struct STRU_ADD_GROUP_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_GROUP_RS() : STRU_PROTOCOL_BASE(DEF_ADD_GROUP_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wResult; 
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];

};
//delete group protocol !!! 
struct STRU_DEL_GROUP_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_GROUP_RQ() : STRU_PROTOCOL_BASE(DEF_DEL_GROUP_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];
};
struct STRU_DEL_GROUP_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_GROUP_RS() : STRU_PROTOCOL_BASE(DEF_DEL_GROUP_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wResult; 
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];

};


//add project protocol
struct STRU_ADD_PRO_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_PRO_RQ() : STRU_PROTOCOL_BASE(DEF_ADD_PRO_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
};
struct STRU_ADD_PRO_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_PRO_RS() : STRU_PROTOCOL_BASE(DEF_ADD_PRO_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wResult; 
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
};

//delete project protocol !
struct STRU_DEL_PRO_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_PRO_RQ() : STRU_PROTOCOL_BASE(DEF_DEL_PRO_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
};
struct STRU_DEL_PRO_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_DEL_PRO_RS() : STRU_PROTOCOL_BASE(DEF_DEL_PRO_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wResult; 
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
};

//join group protocol 
struct STRU_JOIN_GROUP_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_JOIN_GROUP_RQ() : STRU_PROTOCOL_BASE(DEF_JOIN_GROUP_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];//which user in which group
};
struct STRU_ADD_PRO_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_ADD_PRO_RS() : STRU_PROTOCOL_BASE(DEF_JOIN_GROUP_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;
	unsigned short m_wResult; 
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];
};

//leave group protocol 
struct STRU_LEAVE_GROUP_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_LEAVE_GROUP_RQ() : STRU_PROTOCOL_BASE(DEF_LEAVE_GROUP_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];//which user in which group
};
struct STRU_LEAVE_GROUP_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_LEAVE_GROUP_RS() : STRU_PROTOCOL_BASE(DEF_LEAVE_GROUP_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned long m_lUserID;
	unsigned short m_wResult; 
	unsigned short m_wGroupLen;
	char m_szGroup[DEF_GROUP_NAME_LEN];
};

//set power protocol 
struct STRU_SET_POWER_RQ : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_SET_POWER_RQ() : STRU_PROTOCOL_BASE(DEF_SET_POWER_RQ){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned short m_wPowerType;
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
	unsigned long m_lUserID;// when 0 is user
	unsigned short m_wGroupLen;//when is not 0 is group
	char m_szGroup[DEF_GROUP_NAME_LEN];
};
struct STRU_SET_POWER_RS : public STRU_PROTOCOL_BASE{
public:
	static long MIN_LEN;//pack min length help for the seria and unseria
	STRU_SET_POWER_RS() : STRU_PROTOCOL_BASE(DEF_SET_POWER_RS){}
	virtual long Serialize(char* pBuf, long lBufLen);
	virtual bool UnSerialize(const char* pBuf, long lBufLen);
public:
	unsigned 
	unsigned short m_wProLen;
	char m_szPro[DEF_GROUP_NAME_LEN];
	unsigned long m_lUserID;// when 0 is user
	unsigned short m_wGroupLen;//when is not 0 is group
	char m_szGroup[DEF_GROUP_NAME_LEN];
};



#define DEF_SMS_PROTOCOL_COUNT (100)





#endif