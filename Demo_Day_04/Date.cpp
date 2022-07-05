/*
 *文件名： Date.cpp
 *功能模块及目的：实现Date类功能
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

#include "Date.hpp"
#include <string>
using namespace std;
#include <stdexcept>

unsigned int Date::m_MaxYear = 9999;
unsigned int Date::m_MinYear = 1900;

unsigned int Date::m_DefaultYear = 1900;
unsigned int Date::m_DefaultMonth = 1;
unsigned int Date::m_DefaultDay = 1;

unsigned int Date::DaysOfMonth[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
unsigned int Date::DaysSumOfMonth[2][12] = {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};
const unsigned int &Date::MaxYear = Date::m_MaxYear;
const unsigned int &Date::MinYear = Date::m_MinYear;

const unsigned int &Date::DefaultYear = Date::m_DefaultYear;
const unsigned int &Date::DefaultMonth = Date::m_DefaultMonth;
const unsigned int &Date::DefaultDay = Date::m_DefaultDay;

/*
 *函数名：Date
 *函数功能：Date类的构造函数
 *参数：unsigned int Year , unsigned int Month , unsigned int Day
 *返回值：无
 *开发者及日期：Jiashuo Li, 2021/7/27
 *更改记录：
 */

Date::Date() : Year(m_Year), Month(m_Month), Day(m_Day)
{
    set(m_DefaultYear, m_DefaultMonth, m_DefaultDay);
}

Date::Date(unsigned int Year, unsigned int Month, unsigned int Day) : Year(m_Year), Month(m_Month), Day(m_Day)
{
    set(Year, Month, Day);
}

/*
 *函数名：Date
 *函数功能：Date类的拷贝构造函数
 *参数：const Date& c
 *返回值：无
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

Date::Date(const Date &aDate) : Year(m_Year), Month(m_Month), Day(m_Day)
{
    m_Year = aDate.Year;
    m_Month = aDate.Month;
    m_Day = aDate.Day;
}
/*
 *运算符重载
 */
Date &Date::operator=(const Date &aDate)
{
    if (this != &aDate)
    {
        m_Year = aDate.Year;
        m_Month = aDate.Month;
        m_Day = aDate.Day;
    }
    return *this;
}
//未考虑多种日期相加情况，如只加超范围天数、月数、年数
Date &Date::operator+(Date &aDate) const
{
    string error = "Overflow of the Date.";
    Date *Res;
    Res = new Date();
    unsigned int days;
    days = (DaysSumOfMonth[IsLeapYear(Year)][Month - 1] + Day) + (DaysSumOfMonth[IsLeapYear(aDate.Year)][aDate.Month - 1] + aDate.Day);
    unsigned int ResYear;
    unsigned int ResMonth;
    unsigned int ResDay;
    ResYear = Year + aDate.Year + days % (365 + IsLeapYear(Year + aDate.Year));
    if (ResYear > MaxYear)
    {
        throw(error);
    }
    days %= (365 + IsLeapYear(Year + aDate.Year));
    ResMonth = (days + 1) / 30 + 1;
    ResDay = days - DaysSumOfMonth[IsLeapYear(ResYear)][ResMonth - 1];
    Res->m_Day = ResDay;
    Res->m_Month = ResMonth;
    Res->m_Year = ResYear;
    return *Res;
}

unsigned int Date::operator-(const Date &aDate) const
{
    string error = "Invalid subtraction";
    if (*this < aDate)
    {
        throw(error);
    }
    unsigned int days;
    unsigned int LeapYears;
    LeapYears = ((Year - 1) / 4 - (Year - 1) / 100 + (Year - 1) / 400) - ((aDate.Year - 1) / 4 - (aDate.Year - 1) / 100 + (aDate.Year - 1) / 400);
    days = (Year - aDate.Year) * 366 - LeapYears;
    days += (DaysSumOfMonth[IsLeapYear(Year)][Month] + Day) - (DaysSumOfMonth[IsLeapYear(aDate.Year)][aDate.Month] + aDate.Day);
    return days;
}

bool Date::operator>(const Date &aDate) const
{
    return Year > aDate.Year || (Year == aDate.Year && Month > aDate.Month) || (Year == aDate.Year && Month == aDate.Month && Day > aDate.Day);
}
bool Date::operator==(const Date &aDate) const
{
    return Year == aDate.Year && Month == aDate.Month && Day > aDate.Day;
}
bool Date::operator!=(const Date &aDate) const
{
    return !(*this == aDate);
}
bool Date::operator<(const Date &aDate) const
{
    return !(*this > aDate || *this == aDate);
}
bool Date::operator>=(const Date &aDate) const
{
    return !(*this < aDate);
}
bool Date::operator<=(const Date &aDate) const
{
    return !(*this > aDate);
}

/*
 *函数名：set
 *函数功能：设定日期
 *参数：unsigned int Year, unsigned int Month, unsigned int Day
 *返回值：无
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

void Date::set(unsigned int Year, unsigned int Month, unsigned int Day)
{
    string error = "Error: the date isn't valid.";
    if (IsValidDate(Year, Month, Day))
    {
        m_Year = Year;
        m_Month = Month;
        m_Day = Day;
    }
    else
    {
        throw error;
    }
}

/*
 *函数名：IsValidDate
 *函数功能：判断对象是否合法
 *参数：unsigned int Year, unsigned int Month, unsigned int Day
 *返回值：合法，返回true，否则返回false
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */
bool Date::IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day)
{
    if (Year >= MinYear && Year <= MaxYear && Month >= 1 && Month <= 12)
    {
        return Day >= 1 && Day <= DaysOfMonth[!IsLeapYear(Year)][Month - 1];
    }
    return false;
}
bool Date::IsValidDate(const Date &aDate)
{
    return IsValidDate(aDate.Year, aDate.Month, aDate.Day);
}

bool Date::IsValid() const
{
    return IsValidDate(*this);
}

/*
 *函数名：IsLeapYear
 *函数功能：判断是否是闰年
 *参数：unsigned int Year
 *返回值：合法，返回true，否则返回false
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

bool Date::IsLeapYear(unsigned int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool Date::IsLeapYear() const
{
    return IsLeapYear(Year);
}

/*
 *函数名：changerange
 *函数功能：改变年份范围
 *参数：unsigned int maxYear, unsigned int minyear
 *返回值：无
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

void Date::changerange(unsigned int maxyear, unsigned int minyear)
{
    string error = "Error: the range isn't valid.";
    if (maxyear < minyear)
    {
        throw error;
    }
    if (minyear > m_DefaultYear || maxyear < m_DefaultYear)
    {
        throw error;
    }
    m_MaxYear = maxyear;
    m_MinYear = minyear;
}

/*
 *函数名：changedefault
 *函数功能：改变年份范围
 *参数：unsigned int newyear, unsigned int newmonth, unsigned int newday
 *返回值：无
 *开发者及日期：Jiashuo Li, 2022/6/28
 *更改记录：
 */

void Date::changedefault(unsigned int newyear, unsigned int newmonth, unsigned int newday)
{
    string error = "Error: the default values aren't valid";
    if (!IsValidDate(newyear, newmonth, newday))
    {
        throw error;
    }
    if (newyear < m_MinYear || newyear > m_MaxYear)
    {
        throw error;
    }
    m_DefaultYear = newyear;
    m_DefaultMonth = newmonth;
    m_DefaultDay = newday;
}
