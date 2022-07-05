/*
文件名: User.cpp
功能模块及目地: 实现User类的功能
开发者及日期: 李佳硕，2022/6/29
更改记录:
*/

#include "User.hpp"
#include <algorithm>

User::Garbo User::m_Garbo{};
vector<User *> User::m_AllUsers{};
string User::AdminName{"Admin"};
string User::AdminPassword{"Admin"};

/*
函数名：User
函数功能：User类的构造函数，内部构造User类
参数：const string& Name, const string& Password, UserType Type
返回值：无
开发者及日期：Jiashuo Li, 2022/6/29
更改记录：
*/

User::User(const string &Name, const string &Password, UserType Type)
{
    if (Name.empty())
    {
        throw(string("Error: the name is empty!"));
    }
    if (Password.empty())
    {
        throw(string("Error: the password is empty!"));
    }

    m_Name = Name;
    m_Password = Password;
    m_Type = Type;
}

/*
函数名：AddTrivialUser
函数功能：作为对外接口添加TrivialUser
参数：const string& Name, const string& Password
返回值：bool，成功创建，返回true，否则返回false
开发者及日期：Jiashuo Li, 2022/6/29
更改记录：
*/

bool User::AddTrivialUser(const string &Name, const string &Password)
{

    if (Name == AdminName)
    {
        return false;
    }
    bool NotExist = true;
    for_each(std::begin(m_AllUsers), std::end(m_AllUsers), [&](User *p)
             {if(p->m_Name == Name) NotExist = false; });

    if (NotExist)
    {
        m_AllUsers.push_back(new User(Name, Password, UserType::TRIVIAL));
        return true;
    }
    return false;
}

/*
函数名：AddAdministrator
函数功能：作为对外接口添加Administrator，
         用户名唯一，密码可由用户自定义，不指定则为默认
参数：const string& Password
返回值：bool，成功创建，返回true，否则返回false
开发者及日期：Jiashuo Li, 2022/6/29
更改记录：
*/

bool User::AddAdministrator(const string &Password)
{
    bool NotExist = true;
    for_each(std::begin(m_AllUsers), std::end(m_AllUsers), [&](User *p)
             {if(p->m_Name == AdminName) NotExist = false; });

    if (NotExist)
    {
        m_AllUsers.push_back(new User(AdminName, Password, UserType::ADMIN));
        return true;
    }
    return false;
}

/*
函数名：clearAllUsers
函数功能：内部函数清理创建的用户对象
参数：无
返回值：无
开发者及日期：Jiashuo Li, 2022/6/29
更改记录：
*/

void User::clearAllUsers()
{
    for (auto &n : m_AllUsers)
    {
        delete n;
        n = nullptr;
    }
    m_AllUsers.clear();
}

/*
函数名：~Garbo
函数功能：Garbo类的析构函数，系统结束时调用cleanAllUsers
参数：无
返回值：无
开发者及日期：Jiashuo Li, 2022/6/29
更改记录：
*/

User::Garbo::~Garbo()
{
    User::clearAllUsers();
}
