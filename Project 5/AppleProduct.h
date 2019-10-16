#include <string>

#ifndef AppleProduct_h
#define AppleProduct_h

namespace cs31
{
    class AppleProduct
    {
    public:
        enum Kind {NOTSPECIFIED, IPHONE, IPAD, WATCH};
        AppleProduct();
        AppleProduct(Kind kind, std::string version, std::string color, double cost);
        
        std::string getVersion();
        std::string getColor();
        Kind getKind();
        double getCost();
        
    private:
        std::string mVersion;
        std::string mColor;
        double mCost;
        Kind mKind;
    };
}

#endif
