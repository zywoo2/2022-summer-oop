/*
 * 文件名:Date.hpp
 * 功能模块及目的:定义日期类
 * 开发者及日期:李佳硕，2022/6/27
 * 更改记录:无
 */

#ifndef DATE_HPP
#define DATE_HPP
/*
 *类名: Date
 *功能：日期类
 *接口说明：无
 *开发者及日期： 李佳硕, 2022/6/27
 *更改记录：无
 */

class Date
{
public:
    Date(unsigned int Year = 1900, unsigned int Month = 1, unsigned int Day = 1);
    Date(const Date &Src);
    static bool IsValidDate(const Date &Obj);

    const unsigned int &Year;
    const unsigned int &Month;
    const unsigned int &Day;

    static unsigned int Maxyear;
    static unsigned int Minyear;

private:
    unsigned int m_Year;
    unsigned int m_Month;
    unsigned int m_Day;
};

#endif