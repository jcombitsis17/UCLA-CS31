#include "AppleStore.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace cs31
{
    AppleStore::AppleStore()
    {
        //empty but necessary constructor
    }
    
    AppleProduct AppleStore::buyWatch1(std::string color)
    {
        return AppleProduct(AppleProduct::WATCH, "1", color, 249.00);
    }
    
    AppleProduct AppleStore::buyWatch3(std::string color)
    {
        return AppleProduct(AppleProduct::WATCH, "3", color, 329.00);
    }
    
    AppleProduct AppleStore::buyiPad(std::string color, int gigabytes)
    {
        double cost = 0.0;
        
        if (gigabytes == 32)
            cost = 329.00;
        else if (gigabytes == 128)
            cost = 429.00;
        else
        {
            logic_error error("Invalid GB value for iPad");
            throw(error);
        }
        
        return AppleProduct(AppleProduct::IPAD, "", color, cost);
    }
    
    AppleProduct AppleStore::buyiPadPro(std::string color, int gigabytes)
    {
        double cost = 0.0;
        
        if (gigabytes == 64)
            cost = 649.00;
        else if (gigabytes == 256)
            cost = 799.00;
        else if (gigabytes == 512)
            cost = 999.00;
        else
        {
            logic_error error("Invalid GB value for iPadPro");
            throw(error);
        }
        
        return AppleProduct(AppleProduct::IPAD, "Pro", color, cost);
    }
    
    AppleProduct AppleStore::buyiPhoneX(std::string color, int gigabytes)
    {
        double cost = 0.0;
        
        if (gigabytes == 64)
            cost = 999.00;
        else if (gigabytes == 256)
            cost = 1149.00;
        else
        {
            logic_error error("Invalid GB value for iPhone X");
            throw(error);
        }
        
        return AppleProduct(AppleProduct::IPHONE, "X", color, cost);
    }
    
    AppleProduct AppleStore::buyiPhone8(std::string color, int gigabytes)
    {
        double cost = 0.0;
        
        if (gigabytes == 64)
            cost = 699.00;
        else if (gigabytes == 256)
            cost = 849.00;
        else
        {
            logic_error error("Invalid GB value for iPhone 8");
            throw(error);
        }
        
        return AppleProduct(AppleProduct::IPHONE, "8", color, cost);
    }
    
    AppleProduct AppleStore::buyiPhone8Plus(std::string color, int gigabytes)
    {
        double cost = 0.0;
        
        if (gigabytes == 64)
            cost = 799.00;
        else if (gigabytes == 256)
            cost = 949.00;
        else
        {
            logic_error error("Invalid GB value for iPhone 8Plus");
            throw(error);
        }
        
        return AppleProduct(AppleProduct::IPHONE, "8Plus", color, cost);
    }
}
