/*
 * 文件名:main.cpp
 * 功能模块及目的:测试日期类
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */

/*
 * 函数名:main
 * 函数功能:测试日期类
 * 参数: int argc, const char *argv[]
 * 返回值:int
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */
#include <iostream>
#include "Date.hpp"
using namespace std;

int main(int argc, const char *argv[])
{
    freopen("output.txt", "w", stdout);
    unsigned int year;
    unsigned int month;
    unsigned int day;

    cout << "Please input the date" << endl;
    cin >> year >> month >> day;

    Date d1(year, month, day);
    string out = d1.IsValidDate(d1) ? "The date is valid" : "The date isn't valid";
    cout << out << endl;
    return 0;
}
