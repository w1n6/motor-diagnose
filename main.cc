
#include "load_config.h"
#include "fault_tree/fault_tree.h"
#include "mysql_manager/mysql_manager.h"
using namespace std;
int main()
{
    auto cfg = load_config("./config.txt");
    cout << cfg["Host"];
    auto db = new MySqlManager();
    db->InitDB(cfg["Host"], cfg["User"], cfg["Password"], cfg["DBName"]);
    FaultTree ft;
    ft.InitFaultTree(db, 50);
    ft.PrintFaultTree();
}