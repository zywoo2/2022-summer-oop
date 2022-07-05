#ifndef DateTime_hpp
#define DateTime_hpp

#include "Time.hpp"
#include <string>

class DateTime : public Time
{
public:
    DateTime();
    DateTime(unsigned int Year, unsigned int Month, unsigned int Day, Time Time);
    DateTime(const DateTime &Source);
    inline DateTime &operator=(const DateTime &Source);
    inline DateTime &operator+(DateTime &Source) const;
    inline unsigned int operator-(const DateTime &Source) const;

    inline bool operator>(const DateTime &Source) const;
    inline bool operator==(const DateTime &Source) const;
    inline bool operator!=(const DateTime &Source) const;
    inline bool operator<(const DateTime &Source) const;
    inline bool operator>=(const DateTime &Source) const;
    inline bool operator<=(const DateTime &Source) const;

    void setDate(unsigned int Year, unsigned int Month, unsigned int Day);

    virtual std::string GetString() const;

    static bool IsValidDateTime(unsigned int Year, unsigned int Month, unsigned int Day, Time Time);
    static bool IsValidDateTime(const DateTime &Source);
    bool IsValid() const;
    static bool IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day);

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