
#ifndef MYSTRING_H
#define MSTRING_H

#include<iostream>

class MyString
{
    private:
    char *data;
    int length;

    public:
    // default ctor
    MyString();
    // param ctor
    MyString(const char *str);

   //  copy ctor
    MyString(const MyString &other);

    ~MyString();

    int size() const;

    bool empty() const;

    const char *c_str() const;

    char operator[](int index);

    int find(const MyString &substr) const;

    void append(const MyString &other);

    void erase(size_t pos, size_t len);

    // overload insertion operator << for easy output
      friend std::ostream &operator<<(std::ostream &os, const MyString &str);
       
};
#endif 

