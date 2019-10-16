#include <iostream>
#include <string>
#include <cassert>
#include "AppleProduct.h"
#include "AppleStore.h"
using namespace std;
using namespace cs31;

void testWATCH(AppleStore store);                                           //test all specific WATCH cases
void testIPAD(AppleStore store);                                            //test all specific IPAD cases
void testIPHONE(AppleStore store);                                          //test all specific IPHONE cases

int main()
{
    AppleProduct empty;                                                     //test empty AppleProduct constructor
    assert(empty.getKind() == AppleProduct::Kind::NOTSPECIFIED);
    assert(empty.getVersion() == "");
    assert(empty.getColor() == "");
    assert(empty.getCost() == 0.0);
    
    AppleProduct general(AppleProduct::Kind::IPHONE, "X", "Black", 999.00); //test general AppleProduct constructor
    assert(general.getKind() == AppleProduct::Kind::IPHONE);
    assert(general.getVersion() == "X");
    assert(general.getColor() == "Black");
    assert(general.getCost() == 999.00);
    
    AppleStore appleStore;
    
    AppleProduct myiPhone = appleStore.buyiPhone8("Red", 256);              //test general creation of AppleProduct...
    assert(myiPhone.getKind() == AppleProduct::Kind::IPHONE);               //...via AppleStore
    assert(myiPhone.getVersion() == "8");
    assert(myiPhone.getColor() == "Red");
    assert(myiPhone.getCost() == 849.00);
    
    testWATCH(appleStore);
    testIPAD(appleStore);
    testIPHONE(appleStore);
    
    cerr << "ALL TESTS PASSED!" << endl;
}

void testWATCH(AppleStore store)
{
    AppleProduct watch1 = store.buyWatch1("Blue");                          //test Watch Version 1
    assert(watch1.getKind() == AppleProduct::Kind::WATCH);
    assert(watch1.getVersion() == "1");
    assert(watch1.getColor() == "Blue");
    assert(watch1.getCost() == 249.00);
    
    AppleProduct watch3 = store.buyWatch3("Black");                         //test Watch Version 3
    assert(watch3.getKind() == AppleProduct::Kind::WATCH);
    assert(watch3.getVersion() == "3");
    assert(watch3.getColor() == "Black");
    assert(watch3.getCost() == 329.00);
    
    cerr << "All WATCH tests succeeded!" << endl;
}

void testIPAD(AppleStore store)
{
    try
    {
        AppleProduct iPad_32GB = store.buyiPad("Space Grey", 32);           //legal iPad 32GB
        assert(iPad_32GB.getKind() == AppleProduct::Kind::IPAD);
        assert(iPad_32GB.getVersion() == "");
        assert(iPad_32GB.getColor() == "Space Grey");
        assert(iPad_32GB.getCost() == 329.00);
        
        AppleProduct iPad_128GB = store.buyiPad("Pink", 128);               //legal iPad 128GB
        assert(iPad_128GB.getKind() == AppleProduct::Kind::IPAD);
        assert(iPad_128GB.getVersion() == "");
        assert(iPad_128GB.getColor() == "Pink");
        assert(iPad_128GB.getCost() == 429.00);
        
        AppleProduct iPadPro_64GB = store.buyiPadPro("Blue and Gold", 64);  //legal iPadPro 64GB
        assert(iPadPro_64GB.getKind() == AppleProduct::Kind::IPAD);
        assert(iPadPro_64GB.getVersion() == "Pro");
        assert(iPadPro_64GB.getColor() == "Blue and Gold");
        assert(iPadPro_64GB.getCost() == 649.00);
        
        AppleProduct iPadPro_256GB = store.buyiPadPro("Solid Gold", 256);   //legal iPadPro 256GB
        assert(iPadPro_256GB.getKind() == AppleProduct::Kind::IPAD);
        assert(iPadPro_256GB.getVersion() == "Pro");
        assert(iPadPro_256GB.getColor() == "Solid Gold");
        assert(iPadPro_256GB.getCost() == 799.00);
        
        AppleProduct iPadPro_512GB = store.buyiPadPro("White", 512);        //legal iPadPro 512 GB
        assert(iPadPro_512GB.getKind() == AppleProduct::Kind::IPAD);
        assert(iPadPro_512GB.getVersion() == "Pro");
        assert(iPadPro_512GB.getColor() == "White");
        assert(iPadPro_512GB.getCost() == 999.00);
        
        assert(true);
    } catch (logic_error)
    {
        assert(false);
    }
    
    try
    {
        AppleProduct error_iPad = store.buyiPad("Ugly", 64);              //illegal iPad
        assert(false);
    } catch (logic_error)
    {
        assert(true);
    }
    
    try
    {
        AppleProduct error_iPadPro = store.buyiPadPro("Shiny", 128);       //illegal iPadPro
        assert(false);
    } catch (logic_error)
    {
        assert(true);
    }
    
    cerr << "All IPAD tests succeeded!" << endl;
}

void testIPHONE(AppleStore store)
{
    try
    {
        AppleProduct iPhoneX_64GB = store.buyiPhoneX("Black", 64);          //legal iPhoneX 64GB
        assert(iPhoneX_64GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhoneX_64GB.getVersion() == "X");
        assert(iPhoneX_64GB.getColor() == "Black");
        assert(iPhoneX_64GB.getCost() == 999.00);
        
        AppleProduct iPhoneX_256GB = store.buyiPhoneX("Gold", 256);         //legal iPhoneX 256GB
        assert(iPhoneX_256GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhoneX_256GB.getVersion() == "X");
        assert(iPhoneX_256GB.getColor() == "Gold");
        assert(iPhoneX_256GB.getCost() == 1149.00);
        
        AppleProduct iPhone8_64GB = store.buyiPhone8("Rose Gold", 64);      //legal iPhone8 64GB
        assert(iPhone8_64GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhone8_64GB.getVersion() == "8");
        assert(iPhone8_64GB.getColor() == "Rose Gold");
        assert(iPhone8_64GB.getCost() == 699.00);
        
        AppleProduct iPhone8_256GB = store.buyiPhone8("Silver", 256);       //legal iPhone8 256GB
        assert(iPhone8_256GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhone8_256GB.getVersion() == "8");
        assert(iPhone8_256GB.getColor() == "Silver");
        assert(iPhone8_256GB.getCost() == 849.00);
        
        AppleProduct iPhone8Plus_64GB = store.buyiPhone8Plus("Red Orange", 64); //legal iPhone8Plus 64GB
        assert(iPhone8Plus_64GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhone8Plus_64GB.getVersion() == "8Plus");
        assert(iPhone8Plus_64GB.getColor() == "Red Orange");
        assert(iPhone8Plus_64GB.getCost() == 799.00);
        
        AppleProduct iPhone8Plus_256GB = store.buyiPhone8Plus("Rainbow", 256);  //legal iPhone8Plus 256GB
        assert(iPhone8Plus_256GB.getKind() == AppleProduct::Kind::IPHONE);
        assert(iPhone8Plus_256GB.getVersion() == "8Plus");
        assert(iPhone8Plus_256GB.getColor() == "Rainbow");
        assert(iPhone8Plus_256GB.getCost() == 949.00);
        
        assert(true);
    } catch (logic_error)
    {
        assert(false);
    }
    
    try
    {
        AppleProduct error_iPhoneX = store.buyiPhoneX("Brown", 9000);           //illegal iPhoneX
        assert(false);
    } catch (logic_error)
    {
        assert(true);
    }
    
    try
    {
        AppleProduct error_iPhone8 = store.buyiPhone8("Yellow", -55);           //illegal iPhone8
        assert(false);
    } catch (logic_error)
    {
        assert(true);
    }
    
    try
    {
        AppleProduct error_iPhone8Plus = store.buyiPhone8Plus("Cracked Screen", 12345); //illegal iPhone8Plus
        assert(false);
    } catch (logic_error)
    {
        assert(true);
    }
    
    cerr << "All IPHONE tests succeeded!" << endl;
}
