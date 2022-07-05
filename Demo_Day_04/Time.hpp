//
//  Time.hpp
//  DEMO_DAY_01_TIME
//
//  Created by Jingtao Fan on 2022/6/27.
//

#ifndef Time_hpp
#define Time_hpp
#include <string>

class Time
{
public:
    Time(unsigned int Hour = 0, unsigned int Miniute = 0, unsigned int Second = 0);
    Time(const Time &Source);
    bool Set(unsigned int Hour, unsigned int Miniute, unsigned int Second);
    unsigned int Seconds() const;
    const unsigned int &Hour;
    const unsigned int &Minute;
    const unsigned int &Second;
    static bool Is24Hours;
    //    unsigned int Hour();
    //    unsigned int Minute();
    //    unsigned int Second();
    bool SetHour(unsigned int Hour);
    bool SetMinute(unsigned int Minute);
    bool SetSecond(unsigned int Second);
    virtual std::string GetString() const;

private:
    unsigned int m_Hour;
    unsigned int m_Minute;
    unsigned int m_Second;
};

#endif /* Time_hpp */
