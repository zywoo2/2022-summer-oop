#include "DateTime.hpp"
#include <stdexcept>

unsigned int DateTime::m_MaxYear = 9999;
unsigned int DateTime::m_MinYear = 1900;

unsigned int DateTime::m_DefaultYear = 1900;
unsigned int DateTime::m_DefaultMonth = 1;
unsigned int DateTime::m_DefaultDay = 1;

unsigned int DateTime::DaysOfMonth[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
unsigned int DateTime::DaysSumOfMonth[2][12] = {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};
const unsigned int &DateTime::MaxYear = DateTime::m_MaxYear;
const unsigned int &DateTime::MinYear = DateTime::m_MinYear;

const unsigned int &DateTime::DefaultYear = DateTime::m_DefaultYear;
const unsigned int &DateTime::DefaultMonth = DateTime::m_DefaultMonth;
const unsigned int &DateTime::DefaultDay = DateTime::m_DefaultDay;

DateTime::DateTime() : Year(m_Year), Month(m_Month), Day(m_Day), Time()
{
    setDate(DefaultYear, DefaultMonth, DefaultDay);
}
DateTime::DateTime(unsigned int Year, unsigned int Month, unsigned int Day, Time Time) : Year(m_Year), Month(m_Month), Day(m_Day), Time(Time)
{
    if (IsValidDate(Year, Month, Day))
    {
        setDate(Year, Month, Day);
    }
    else
    {
        throw(std::string("The date isn't valid!"));
    }
}

bool DateTime::IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day)
{
    if (Year >= MinYear && Year <= MaxYear && Month >= 1 && Month <= 12)
    {
        return Day >= 1 && Day <= DaysOfMonth[!IsLeapYear(Year)][Month - 1];
    }
    return false;
}

bool DateTime::IsLeapYear(unsigned int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
bool DateTime::IsLeapYear() const
{
    return IsLeapYear(Year);
}
