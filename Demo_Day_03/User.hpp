/*
文件名: User.hpp
功能模块及目地: 定义User类
开发者及日期: 李佳硕，2022/6/29
更改记录:
*/

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

using namespace std;
/*
类名：UserType
功能：定义用户类型
接口说明： 无
开发者及日期：李佳硕， 2022/6/29
更改记录：
*/

enum class UserType
{
    TRIVIAL,
    ADMIN
};

/*
类名：User
功能：实现不同用户（trivial、admin）的创建管理， 以及销毁功能
接口说明：AddTrivialUser(), AddTrivialUser(), 添加用户
开发者及日期：李佳硕， 2022/6/29
更改记录：
*/

class User
{

public:
    User() = delete;
    User(const User &) = delete;
    User &operator=(const User &) = delete;

    static bool AddTrivialUser(const string &Name, const string &Password);
    static bool AddAdministrator(const string &Password = AdminPassword);

private:
    User(const string &Name, const string &Password, UserType Type);

    string m_Name;
    string m_Password;
    UserType m_Type;

    static vector<User *> m_AllUsers;

    /*
    类名：Garbo
    功能：作为User类的内嵌类，实例化静态对象以在结束时清理创建的用户对象
    接口说明：无
    开发者及日期：李佳硕， 2022/6/29
    更改记录：
    */

    class Garbo
    {
    public:
        ~Garbo();
    };
    static Garbo m_Garbo;

    static string AdminName;
    static string AdminPassword;
    static void clearAllUsers();
};

#endif /*USER_HPP*/