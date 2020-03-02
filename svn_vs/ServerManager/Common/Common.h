//constant define
#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__

#define DEF_MAX_PASS_LEN     (15)
#define DEF_GROUP_NAME_LEN   (20)
#define DEF_MAX_PROJECT_LEN  (20)//pro name
enum ENUM_RS_RES{
	enum_rs_success,
	enum_rs_fail,
	enum_rs_exist,//add user
	enum_rs_unexist,//delete user
};
enum ENUM_POWER_TYPE{
	enum_power_readonlu,
	enum_power_unaccess,
	enum_power_access,//include the write and read
};
enum ENUM_GROUP_OPR_TYPE
{
	enum_group_opr_add,
	enum_group_opr_del,
};





#endif//__COMMON_H__