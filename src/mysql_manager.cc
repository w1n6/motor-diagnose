#include "mysql_manager/mysql_manager.h"
#include <mysql/mysql.h>
#include <iostream>

using namespace std;

void DataSet::PrintDataSet()
{
    cout << this->row << endl;
    cout << this->column << endl;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->column; j++)
        {
            cout << this->records[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

MySqlManager::MySqlManager()
{
    connection = mysql_init(nullptr); //初始化数据库连接变量
    if (connection == nullptr)
    {
        cout << "mysql_init error!" << endl;
        exit(1);
    }
}

MySqlManager::~MySqlManager()
{
    if (result != nullptr)
    {
        // 释放结果集的内存
        mysql_free_result(result);
    }
    if (connection != nullptr)
    {
        mysql_close(connection);
    }
}

bool MySqlManager::InitDB(string host, string user, string pwd, string db_name)
{
    // 函数mysql_real_connect建立一个数据库连接
    // 成功返回MYSQL*连接句柄, 失败返回NULL
    connection = mysql_real_connect(connection, host.c_str(), user.c_str(), pwd.c_str(), db_name.c_str(), 0, nullptr, 0);
    if (connection == nullptr)
    {
        cout << "mysql_real_connect error!" << endl;
        return false;
    }
    return true;
}
bool MySqlManager::ExecuteSql(const char *sql)
{
    if (mysql_query(connection, sql) != 0)
    {
        cout << "mysql_execute error!" << endl;
        return false;
    }
    else
    {
        cout << "mysql_execute sucess!" << endl;
        return true;
    }
}

bool MySqlManager::QuerySql(const char *sql)
{
    // mysql_query()执行成功返回字符串数组, 失败返回false.
    if (mysql_query(connection, sql) != 0)
    {
        cout << "mysql_query error!" << endl;
        return false;
    }
    else
    {
        result = mysql_store_result(connection); //获取结果集
        cout << "mysql_query sucess!" << endl;
        return true;
    }
}
DataSet *MySqlManager::GetDataSet()
{
    int r = mysql_num_rows(result);
    int c = mysql_num_fields(result);
    auto rs = new record[r];
    for (int i = 0; i < r; ++i)
    {
        row = mysql_fetch_row(result);
        rs[i] = row;
    }
    return new DataSet(mysql_num_fields(result), mysql_num_rows(result), rs);
}