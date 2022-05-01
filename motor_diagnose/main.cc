#include "mysql_manager/mysql_manager.h"

int main()
{
    MySqlManager db;
    db.InitDB("localhost","wind","123456","motor_diagnose");
    if (db.QuerySql("select * from motor_fault_tree"))
    {
        DataSet* ds =  db.GetDataSet();
        // for (int i=0;i<ds->row;++i)
        // {
        //     for (int j=0;j<ds->column;++j)
        //     {
        //         cout<<ds->records[i][j]<<endl;   
        //     }
        // }
        cout<<ds->column<<endl;
        cout<<ds->row<<endl;
        cout<<ds->records[32];
    }
    return 0;
}