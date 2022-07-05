/*
 *文件名： main.cpp
 *功能模块及目的：检验Date类的功能
 *开发人员及日期： Jiashuo Li, 2022/6/28
 *更改记录：
 */

#include <iostream>
#include <string>
#include "Date.hpp"
using namespace std;

/*
 *函数名：main
 *函数功能：主函数
 *参数：int argc, const char *argv[]
 *返回值：0
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

int main(int argc, const char *argv[])
{
    unsigned int year;
    unsigned int month;
    unsigned int day;

    cout << "Please input the date" << endl;
    cin >> year >> month >> day;

    try
    {
        Date d1(year, month, day);
    }
    catch (string error)
    {
        cout << error << endl;
        return 0;
    }
    cout << "The date is valid" << endl;

    return 0;
    //检验changerange()函数
    /*
    int maxyear;
    int minyear;

    cin >> maxyear >> minyear;
    try { Date::changerange(maxyear, minyear); }
    catch(string error)
    {
        cout << error << endl;
    }
    return 0;
    */

    //检验函数changedefault()的功能
    /*
    int nyear;
    int nmonth;
    int nday;

    cin >> nyear >> nmonth >> nday;
    try { Date::changedefault(nyear, nmonth, nday); }
    catch(string error)
    {
        cout << error << endl;
    }
    return 0;

    */
}
