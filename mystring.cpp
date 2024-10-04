#include "MyString.h"
#include <cstring>

MyString :: MyString()
{
    data = new char[1];
    length =0;
    data[0] = '\0';
}

MyString :: MyString(const char *str)
{
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}

MyString :: MyString(const MyString &other)
{
    data = new char[other.length +1];
    length = other.length;
    strcpy(data, other.data);
} 

MyString :: ~MyString()
{
    delete[] data;
}

int MyString :: size() const
{
    return length;
}

bool MyString :: empty() const
{
    return length == 0;
}

const char *MyString::c_str() const
{
    return data;
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
    return os;
}

char MyString::operator[](int index)
{
    if(index >= length){
        return '\0';
    }
    return data[index];
}

 int MyString::find(const MyString &substr) const
 {
    if(substr.length >length)
         return -1;

    for(int i=0; i <= length-substr.length; i++)
    {
        int j;
        for(j=0; j<substr.length; j++)
        {
           if(data[i +j] != substr.data[j])
           {
              break;
           }
        }
        if(j == substr.length)
             return i;
    }
    return -1;     
 }

 void MyString::append(const MyString &other)
{
    *this  += other;
}

void MyString::erase(size_t pos, size_t len) {
    if (pos >= length) {
        throw std::out_of_range("Position out of range");
    }
    
    if (len == 0) {
        return;
    }
    
    if (len > length - pos) {
        len = length - pos; // Erase till the end if len exceeds the string length from pos
    }

    // Calculate new length
    size_t newLength = length - len;
    
    // Create new data array
    char *newData = new char[newLength + 1];
    
    // Copy characters before 'pos'
    strncpy(newData, data, pos);
    
    // Copy characters after 'pos + len'
    strcpy(newData + pos, data + pos + len);
    
    // Null-terminate the new string
    newData[newLength] = '\0';
    
    // Delete old data and replace with new data
    delete[] data;
    data = newData;
    
    // Update length
    length = newLength;
}