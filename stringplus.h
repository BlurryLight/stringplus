#ifndef STRINGPLUS_H
#define STRINGPLUS_H
#include <string>
#include <vector>

namespace stringplus
{
    bool isalnum(const std::string& str);
    bool isalpha(const std::string& str);
    bool isdigit(const std::string& str);
    bool islower(const std::string& str);

    std::string to_upper(const std::string& str);
    std::string to_lower(const std::string& str);
    std::string trim(const std::string& str);
    std::string strip(const std::string& str,const std::string& chars = "");
    std::string lstrip(const std::string& str,const std::string& chars = "");
    std::string rstrip(const std::string& str,const std::string& chars = "");

    std::vector<std::string> split(const std::string& str,const std::string& sep ,int maxsplit);
    std::string join(const std::string& str,const std::vector<std::string>& seq);

}

#endif // STRINGPLUS_H
