#include <iostream>
#include <vector>
#include <mysql/mysql.h>
#include "fault_tree/fault_tree.h"
#include "mysql_manager/mysql_manager.h"

using namespace std;

vector<Event *> GetFaultEvent(MySqlManager *db, const char *sn, const char *name, const char *level, const char *parent, const char *relation)
{
    char str[500];
    sprintf(str, "select * from motor_fault_tree where sn like \'%s\' and name like \'%s\' and level like \'%s\' and parent like \'%s\' and relation like \'%s\' ", sn, name, level, parent, relation);
    const char *sql = str;
    // cout << string(sql) << endl;
    db->QuerySql(sql);
    auto ds = db->GetDataSet();
    // ds->PrintDataSet();
    auto vec = vector<Event *>();
    for (int i = 0; i < ds->row; i++)
    {
        auto e = new Event();
        e->name = ds->records[i][NAME];
        e->level = ds->records[i][LEVEL];
        if (ds->records[i][RELATION] == "与")
        {
            e.relation = true;
        }
        else
        {
            e.relation = false;
        }
        vec.push_back(e);
    }
    return e;
}
void FaultTree::InitFaultTreeHelper(Event *father)
{
    if (father->level == "底事件")
    {
        father->child_num = 0;
        return;
    }
    vector<Event *> child_events = GetFaultEvent(db, "%", "%", "%", father->name.c_str(), "%");

    events_num++;
    for (int i = 0; i < length; i++)
    {
        child[i].parent = father;
        InitFaultTreeHelper(db, events, events_num, &child[i]);
    }
}

//构造故障树
void FaultTree::InitFaultTree(MySqlManager *db)
{
    events = new Event *[event_num];
    int length = 0;
    top = GetFaultEvent(db, &length, top_sn.c_str(), "%", "%", "%", "%");
    top[0].parent = nullptr;
    int events_num = 0;
    // InitFaultTreeHelper(db, events, event_num, top);
}

void FaultTree::PrintFaultTree()
{
    cout << events[10][1].name << endl;
    // for (int i = events_num - 1; i >= 0; i--)
    // {
    //     Event *e = events[i];
    //     while (e->parent != nullptr)
    //     {
    //         cout << e->name << endl;
    //         e = e->parent;
    //     }
    // }
}