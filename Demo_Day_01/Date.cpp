/*
 *文件名:Date.cpp
 *功能模块及目的:实现Date类
 *开发者及日期:李佳硕，2022/6/27
 *更改记录:无
 */

#include "Date.hpp"

unsigned int Date::Maxyear = 9999;
unsigned int Date::Minyear = 1900;

/*
 * 函数名:Date
 * 函数功能:Date类的带默认参数构造函数
 * 参数:unsigned int Year , unsigned int Month , unsigned int Day
 * 返回值:无
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */

Date::Date(unsigned int Year, unsigned int Month, unsigned int Day) : Year(m_Year), Month(m_Month), Day(m_Day)
{
    m_Year = Year;
    m_Month = Month;
    m_Day = Day;
}

/*
 * 函数名:Date
 * 函数功能:Date类的拷贝构造函数
 * 参数:const Date &Src
 * 返回值:无
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */

Date::Date(const Date &Src) : Year(m_Year), Month(m_Month), Day(m_Day)
{
    m_Year = Src.Year;
    m_Month = Src.Month;
    m_Day = Src.Day;
}

/*
 * 函数名:IsValidDate
 * 函数功能:Date类的静态成员函数，判断日期是否合理
 * 参数:unsigned int Year, unsigned int Month, unsigned int Day
 * 返回值:bool型表示是否合理
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */

bool Date::IsValidDate(const Date &Obj)
{
    unsigned int Year = Obj.Year;
    unsigned int Month = Obj.Month;
    unsigned int Day = Obj.Day;
    if (Year >= Minyear && Year <= Maxyear)
    {
        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
        {
            return Day >= 1 && Day <= 31;
        }
        if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        {
            return Day >= 1 && Day <= 30;
        }
        if (Month == 2)
        {
            if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
            {
                return Day >= 1 && Day <= 29;
            }
            else
            {
                return Day >= 1 && Day <= 29;
            }
        }
        return false;
    }
    return false;
}
