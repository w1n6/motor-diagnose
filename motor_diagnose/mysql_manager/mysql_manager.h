#pragma once

#include <iostream>
#include <mysql/mysql.h>
#include <string>

typedef char **record; //查询记录

using namespace std;

//结果集
struct DataSet
{
public:
    int row;         //行数
    int column;      //列数
    record *records; //查询记录

    // c: 行数, r: 列数, rs: 查询记录
    DataSet(int c, int r, record *rs)
    {
        this->column = c;
        this->row = r;
        this->records = rs;
    }
    ~DataSet()
    {
        delete this->records;
    }
};

// mysql包装
class MySqlManager
{
public:
    MySqlManager();
    ~MySqlManager();
    // 初始化数据库连接
    bool InitDB(string host, string user, string pwd, string db_name);
    // 释放连接
    bool FreeConnect();

    // 执行sql, 增删改操作
    // bool ExecuteSql(const char *sql);
    // 执行查询语句
    bool QuerySql(const char *sql);
    //返回查询结果
    DataSet* GetDataSet();

private:
    MYSQL *connection; //连接mysql句柄指针
    MYSQL_RES *result; //指向查询结果的指针
    MYSQL_ROW row;     //按行返回的查询信息
};