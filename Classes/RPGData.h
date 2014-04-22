//
//  RPGData.h
//  OzgGameRPG
//
//  Created by ozg on 14-4-5.
//
//

#ifndef __OzgGameRPG__RPGData__
#define __OzgGameRPG__RPGData__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

enum RPGDataStatus {
    kRPGDataStatusNormal = 1, //通常时
    kRPGDataStatusDeath = 2 //战斗不能
    
};

class RPGPlayer : public CCObject
{
    
public:
    
    int m_dataId;
    string m_name;
    int m_maxHP;
    int m_HP;
    int m_maxMP;
    int m_MP;
    float m_attack;
    float m_defense;
    float m_speed;
    float m_skillAttack;
    float m_skillDefense;
    int m_itemsIdArms;
    int m_itemsIdArmor;
    int m_level;
    string m_skill;
    int m_nextExp;
    string m_texPrefix;
    int m_exp; //总经验值
    
    float m_progress; //进度条，数据库没有这个字段
    
    RPGDataStatus m_status; //对象状态，数据库暂时没有这个字段
    
    RPGPlayer();
    virtual ~RPGPlayer();
    
    static RPGPlayer* create();
    
};

class RPGMonster : public CCObject
{
    
public:
    
    int m_dataId;
    string m_name;
    int m_maxHP;
    int m_HP; //数据库里面没有这个字段
    float m_attack;
    float m_defense;
    float m_speed;
    float m_skillAttack;
    float m_skillDefense;
    int m_exp;
    string m_skill;
    string m_tex;
    int m_gold;
    
    int m_tag; //格式为 enum tag + 0到999的无重复数（就算同一个怪物也不能重复）
    
    float m_progress; //进度条，数据库没有这个字段
    
    RPGDataStatus m_status; //对象状态，数据库暂时没有这个字段
    
    RPGMonster();
    virtual ~RPGMonster();
    
    static RPGMonster* create();
    
};

class RPGSkill : public CCObject
{
    
public:
    int m_dataId;
    string m_name;
    float m_skillAttack;
    int m_MP;
    int m_type;
    
    RPGSkill();
    virtual ~RPGSkill();
    
    static RPGSkill* create();
};

class RPGItems : public CCObject
{
    
public:
    
    int m_dataId;
    string m_name;
    float m_buy;
    float m_sell;
    int m_type;
    float m_attack;
    float m_defense;
    float m_speed;
    float m_skillAttack;
    float m_skillDefense;
    
    RPGItems();
    virtual ~RPGItems();
    
    static RPGItems* create();
    
};

//现有道具
class RPGExistingItems : public RPGItems
{
    
public:
    
    int m_total; //该道具的个数
    
    RPGExistingItems();
    virtual ~RPGExistingItems();
    
    static RPGExistingItems* create();
};

#endif /* defined(__OzgGameRPG__RPGData__) */
