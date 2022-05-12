#pragma once

#include <iostream>
#include <mysql/mysql.h>

#define ID 0
#define SN 1
#define NAME 2
#define LEVEL 3
#define PARENT 4
#define RELATION 5

typedef char **record; //查询记录

using namespace std;

//结果集
struct DataSet
{
public:
    // c: 列数, r: 行数, rs: 查询记录
    DataSet(int c, int r, record *rs)
    {
        this->column = c;
        this->row = r;
        this->records = rs;
    }
    void PrintDataSet();

public:
    int row;         //行数
    int column;      //列数
    record *records; //查询记录
};

// mysql包装类
class MySqlManager
{
public:
    // 初始化数据库连接
    bool InitDB(string host, string user, string pwd, string db_name);
    // 释放连接
    bool FreeConnect();

    // 执行sql, 增删改操作
    bool ExecuteSql(const char *sql);
    // 执行查询语句
    bool QuerySql(const char *sql);
    //返回查询结果
    DataSet *GetDataSet();

public:
    MySqlManager();
    ~MySqlManager();

private:
    MYSQL *connection; //连接mysql句柄指针
    MYSQL_RES *result; //指向查询结果的指针
    MYSQL_ROW row;     //按行返回的查询信息
};