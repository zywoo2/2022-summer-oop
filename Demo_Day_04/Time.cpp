//
//  Time.cpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2022/6/27.
//

#include "Time.hpp"
#include <string>

bool Time::Is24Hours = true;

Time::Time(unsigned int Hour, unsigned int Miniute, unsigned int Second) : Hour(m_Hour), Minute(m_Minute), Second(m_Second)
{
    if (!Set(Hour, Miniute, Second))
    {
        Set(0, 0, 0);
    }
}

Time::Time(const Time &Source) : Hour(m_Hour), Minute(m_Minute), Second(m_Second)
{
    m_Hour = Source.m_Hour;
    m_Minute = Source.m_Minute;
    m_Second = Source.m_Second;
}

bool Time::Set(unsigned int Hour, unsigned int Miniute, unsigned int Second)
{
    return SetHour(Hour) && SetMinute(Miniute) && SetSecond(Second);
}
//---------------------------------------------------
bool Time::SetHour(unsigned int Hour)
{
    bool IsRight = Hour < 24;
    m_Hour = IsRight ? Hour : m_Hour;
    return IsRight;
}
//---------------------------------------------------
bool Time::SetMinute(unsigned int Minute)
{
    bool IsRight = Minute < 60;
    m_Minute = IsRight ? Minute : m_Minute;
    return IsRight;
}
//---------------------------------------------------
bool Time::SetSecond(unsigned int Second)
{
    bool IsRight = Second < 60;
    m_Second = IsRight ? Second : m_Second;
    return IsRight;
}
//---------------------------------------------------
unsigned int Time::Seconds() const
{
    return m_Hour * 3600u + m_Minute * 60u + m_Second;
}
//---------------------------------------------------
std::string Time::GetString() const
{
    std::string Temp;
    if (Is24Hours)
    {
        return Temp;
    }
    else
    {
        return Temp;
    }
}
