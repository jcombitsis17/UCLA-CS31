#include "AppleProduct.h"

#ifndef AppleStore_h
#define AppleStore_h

namespace cs31
{
    class AppleStore
    {
    public:
        AppleStore();
        
        AppleProduct buyWatch1(std::string color);
        AppleProduct buyWatch3(std::string color);
        
        AppleProduct buyiPad(std::string color, int gigabytes);
        AppleProduct buyiPadPro(std::string color, int gigabytes);
        
        AppleProduct buyiPhoneX(std::string color, int gigabytes);
        AppleProduct buyiPhone8(std::string color, int gigabytes);
        AppleProduct buyiPhone8Plus(std::string color, int gigabytes);
    };
}

#endif
