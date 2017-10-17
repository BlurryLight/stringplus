#include "stringplus.h"
#include <algorithm>
namespace stringplus {
typedef std::string::size_type strtype;
#define MAX32BITINT 2147483647
///basis functions set in a anonymous namespace
namespace   {
enum
{leftstrip = 0,
    rightstrip = 1,
    bothstrip = 2
};
std::string strip_do(const std::string& str,int striptype,const std::string& chars)
{
    std::string s(str);
    if(chars.length() == 0)
        return trim(s);
    if(striptype == 0)
    {
    s.erase(0,s.find_first_not_of(chars));
    }
    else if(striptype == 1)
    {
    s.erase(s.find_last_not_of(chars) + 1);
    }
    else
    {
    s.erase(0,s.find_first_not_of(chars));
    s.erase(s.find_last_not_of(chars) + 1);
    }
    return s;
}
}

//using generic algorithm std::transform
std::string to_upper(const std::string& str)
{

    std::string s(str);

    std::transform(s.begin(),s.end(),s.begin(),toupper);
    return s;
}
std::string  to_lower(const std::string& str)
{
    std::string s(str);

    std::transform(s.begin(),s.end(),s.begin(),tolower);
    return s;

}

bool isalnum(const std::string& str)
{
    strtype len = str.size();
    if(len == 0) return false;

    for(strtype i=0;i!=len;++i)
    {
        if(!::isalnum(str[i])) return false;
    }
    return true;
}
bool isalpha(const std::__cxx11::string &str)
{
    strtype len = str.size();
    if(len == 0) return false;

    for(strtype i=0;i!=len;++i)
    {
        if(!::isalpha(str[i])) return false;
    }
    return true;
}

bool isdigit(const std::__cxx11::string &str)
{

    strtype len = str.size();
    if(len == 0) return false;

    for(strtype i=0;i!=len;++i)
    {
        if(!::isalpha(str[i])) return false;
    }
    return true;
}

//bool istitle(const std::__cxx11::string &str)
//{

//    strtype len = str.size();
//    if(len == 0) return false;
//    if(len == 1) return ::isuper(str[0]);
//    for(strtype i=0;i!=len;++i)
//    {
//        if(!::islower(str[i])) return false;
//    }
//    return true;
//}
bool islower(const std::__cxx11::string &str)
{

    strtype len = str.size();
    if(len == 0) return false;

    for(strtype i=0;i!=len;++i)
    {
        if(!::islower(str[i])) return false;
    }
    return true;
}

std::__cxx11::string trim(const std::__cxx11::string &str)
{
    std::string s(str);
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;

}

std::__cxx11::string strip(const std::__cxx11::string &str, const std::__cxx11::string &chars)
{
    return strip_do(str,bothstrip,chars);
}

std::__cxx11::string lstrip(const std::__cxx11::string &str, const std::__cxx11::string &chars)
{
    return strip_do(str,leftstrip,chars);
}
std::__cxx11::string rstrip(const std::__cxx11::string &str, const std::__cxx11::string &chars)
{
    return strip_do(str,leftstrip,chars);
}

std::vector<std::__cxx11::string> split(const std::__cxx11::string &str, const std::__cxx11::string &sep, int maxsplit=-1)
{
    if(maxsplit<0) maxsplit=MAX32BITINT;

    if(sep.size()==0)
    {
        return split(str," ",maxsplit);
    }
    std::vector<std::string> result;
    strtype len = str.size(),n=sep.size();
    strtype i=0,j=0;
    while(i + n <= len)
    {
        if(str[i] == sep[0] && str.substr(i,n) == sep)
        {
            if(maxsplit <0) return result;

            maxsplit --;
            result.push_back(str.substr(j,i-j));
            i = j = i + n;
        }
        else
        {
            i++;
        }
    }
    result.push_back(str.substr(j,len-j));
    return result;
}


std::string join(const std::string& str,const std::vector<std::string>& seq)
{
    if(seq.size() == 0) return "";
    if(seq.size() == 1) return seq[0];
    std::string result(seq[0]);
    for(auto it = seq.cbegin() + 1;it!=seq.cend();++it)
        result += str + *it;
    return result;
}

bool istitle(const std::__cxx11::string &str)
{
    strtype len = str.size();
    if(len ==0) return false;
    if(len ==1 )return ::isupper(str[0]);

bool res = false , previouscased = false;
    for(auto it = str.cbegin();it!=str.cend();++it)
    {
        if(::isupper(*it))
        {
            if(previouscased == true)
            {
                return false;
            }
            res = true;
            previouscased = true;
        }
        else if(::islower(*it))
        {
            if(previouscased == false)
            {
                return false;
            }
            previouscased = true;
            res = true;
        }
        else
        {
            previouscased = false;
        }

    }
    return res;

}

}
