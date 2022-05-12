#include <httplib.h>

using namespace httplib;

void helloworld(Request &req, Response &rsp)
{
    rsp.set_content("Hello World", "text/html");
    rsp.status = 200;
}
int main()
{
    Server srv; // 创建服务端对象
    srv.Get("/", helloworld);
    srv.listen("0.0.0.0", 9000); // 0.0.0.0 本机的任意一块网卡地址， 9000端口
}