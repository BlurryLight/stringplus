#include "stringplus.h"
#include <string>
#include <iostream>
int main()
{
    std::string a = std::string(" az2zxcvs2adf ad0202020");
  //  std::cout<<stringplus::trim(a)<<std::endl;
   // std::cout<<stringplus::strip(a," ")<<std::endl;
    auto b = stringplus::split(a,"2",-1);
    for(auto it=b.cbegin();it!=b.cend();it++)
        std::cout<<*it<<std::endl;
}
