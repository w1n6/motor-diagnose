#pragma once
#include <vector>
#include "mysql_manager/mysql_manager.h"

using namespace std;

//事件
class Event
{
public:
    string name;       //事件名称
    string level;      //故障层级
    float possibility; //发生的可能性
    Event *parent;     //父事件
    int child_num;     //子事件数量
    bool relation;     //子事件的关系
    bool *isactive;    //子事件的激活信号
};

class FaultTree
{
public:
    void InitFaultTree(MySqlManager *db, int event_num); //初始化一个故障树
    char **Active(string event_name, float possibility); //根据 事件名:概率值  的一个 k:v对 去激活底层事件, 并返回一个结果。
    // ~FaultTree();
    void InitFaultTreeHelper(Event *father);
    void PrintFaultTree();

private:
    string top_sn;
    Event *top;
    static vector<Event *> events;
};