/*
 *文件名 : Date.hpp
 *功能模块及目的：定义Date类
 *开发者及日期： Jiashuo Li, 2022/6/28
 *更改记录：
 */

#ifndef Date_hpp
#define Date_hpp

/*
 *类名: Date
 *功能：日期类，判断日期是否合理
 *接口说明：无
 *开发者及日期： Jiashuo Li, 2022/6/28
 *更改记录：
 */

class Date
{
public:
    Date();
    Date(unsigned int Year, unsigned int Month, unsigned int Day);
    Date(const Date &aDate);
    inline Date &operator=(const Date &aDate);
    inline Date &operator+(Date &aDate) const;
    inline unsigned int operator-(const Date &aDate) const;

    inline bool operator>(const Date &aDate) const;
    inline bool operator==(const Date &aDate) const;
    inline bool operator!=(const Date &aDate) const;
    inline bool operator<(const Date &aDate) const;
    inline bool operator>=(const Date &aDate) const;
    inline bool operator<=(const Date &aDate) const;

    void set(unsigned int Year, unsigned int Month, unsigned int Day);

    static bool IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day);
    static bool IsValidDate(const Date &aDate);
    bool IsValid() const;

    inline static bool IsLeapYear(unsigned int Year);
    inline bool IsLeapYear() const;

    const unsigned int &Year;
    const unsigned int &Month;
    const unsigned int &Day;

    static const unsigned int &MaxYear;
    static const unsigned int &MinYear;

    static const unsigned int &DefaultYear;
    static const unsigned int &DefaultMonth;
    static const unsigned int &DefaultDay;

    static void changerange(unsigned int maxyear, unsigned int minyear);
    static void changedefault(unsigned int newyear, unsigned int newmonth, unsigned int newday);

private:
    unsigned int m_Year;
    unsigned int m_Month;
    unsigned int m_Day;

    static unsigned int DaysOfMonth[2][12];
    static unsigned int DaysSumOfMonth[2][12];
    static unsigned int m_MaxYear;
    static unsigned int m_MinYear;

    static unsigned int m_DefaultYear;
    static unsigned int m_DefaultMonth;
    static unsigned int m_DefaultDay;
};

#endif