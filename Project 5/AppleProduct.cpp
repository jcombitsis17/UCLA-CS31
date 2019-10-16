#include "AppleProduct.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace cs31
{
    AppleProduct::AppleProduct()
    {
        mKind = NOTSPECIFIED;
        mVersion = "";
        mColor = "";
        mCost = 0.0;
    }
    
    AppleProduct::AppleProduct(Kind kind, string version, string color, double cost)
    {
        mKind = kind;
        mVersion = version;
        mColor = color;
        mCost = cost;
    }
    
    string AppleProduct::getVersion()
    {
        return mVersion;
    }
    
    string AppleProduct::getColor()
    {
        return mColor;
    }
    
    AppleProduct::Kind AppleProduct::getKind()
    {
        return mKind;
    }
    
    double AppleProduct::getCost()
    {
        return mCost;
    }

}
