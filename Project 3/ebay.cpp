//Jordan Combitsis
//UID: 004-921-527

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);
int number(string s, int& startingposition);

int calcWatchers(string auctionstring);                 //checks if more U than W
bool calcBids(string auctionstring);                    //detects 'B' and 'B+' error cases
int totalBid(string auctionstring);                     //calculates the total final bid
int getListing(string auctionstring);                   //returns initial list price

int main()
{
    assert(isValidEbayListingString("L99B50WB+10UWB+40W"));     //true
    assert(isValidEbayListingString("l99b50wb+10uwb+40w"));
    assert(isValidEbayListingString("L100B99"));
    assert(isValidEbayListingString("L100B50WWWWWWW"));
    assert(isValidEbayListingString("L100B50WUWUWUWWWWW"));
    assert(isValidEbayListingString("L100B50WWUUB+10WWUU"));
    assert(isValidEbayListingString("L100W"));
    assert(isValidEbayListingString("L100WU"));
    assert(isValidEbayListingString("L100B50WU"));
    assert(isValidEbayListingString("L100WUB50"));
    
    assert(!isValidEbayListingString(""));                      //false
    assert(!isValidEbayListingString("  "));
    assert(!isValidEbayListingString("LBWU"));
    assert(!isValidEbayListingString("L100WB50UU"));
    assert(!isValidEbayListingString("L100 B50 W B+10 U W B+40 W"));
    assert(!isValidEbayListingString("L100.50B50"));
    assert(!isValidEbayListingString("L100B50UW"));
    assert(!isValidEbayListingString("L100BW50"));
    assert(!isValidEbayListingString("L100B50WBU+50"));
    assert(!isValidEbayListingString("L100B50UUUUUUUUU"));
    assert(!isValidEbayListingString("L100B50WWUUUUUUUUU"));
    assert(!isValidEbayListingString("WUL100"));
    assert(!isValidEbayListingString("L100L50"));
    assert(!isValidEbayListingString("L100B+50"));
    assert(!isValidEbayListingString("L100B50B+50B20"));
    assert(!isValidEbayListingString("L100WUWB50UUWWB+65"));
    
    cerr << "All tests passed!" << endl;
    
    string auctionstring;
    cout << "Enter String: ";
    getline(cin, auctionstring);
    
    bool valid = isValidEbayListingString(auctionstring);       //if (valid) then do the other 3 functions
    bool sold = listingSold(auctionstring);
    int price = howMuch(auctionstring);
    int w = watchers(auctionstring);
    
    if (valid)
    {
        cout << "Valid string!" << endl;
        if (sold)
        {
            cout << "The listing sold for " << price << " dollars." << endl;
            cout << "There were " << w << " watchers at the end of the auction." << endl;
        } else
        {
            cout << "The listing of " << getListing(auctionstring) << " did not sell." << endl;
        }
    } else
    {
        cout << "INVALID string!" << endl;
    }
    
    return 0;
}

bool isValidEbayListingString(string auctionstring)
{
    size_t length = auctionstring.length();
    if (length == 0)
    {
        return false;
    }
    
    int totalWatchers = calcWatchers(auctionstring);
    if (totalWatchers < 0)
    {
        return false;
    }
    
    bool countBids = calcBids(auctionstring);
    if (!countBids)
    {
        return false;
    }
    
    bool validString = false;
    for (size_t i = 0; i < length; i++)
    {
        char c = auctionstring[i];
        switch(c)
        {
            case 'L': case 'l':
            if (i == 0)
            {
                validString = true;
            } else
            {
                return false;
            }
            break;
            
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                if (auctionstring[i - 1] == 'L' || auctionstring[i - 1] == 'l' ||       //valid first int
                    auctionstring[i - 1] == 'B' || auctionstring[i - 1] == 'b' ||
                    auctionstring[i - 1] == '+')
                {
                    if (auctionstring[i] == '0')      //leading zero = invalid
                    {
                        return false;
                    }
                }
                
                if (auctionstring[i - 1] >= '0' && auctionstring[i - 1] <= '9')         //valid non-initial int
                {
                    validString = true;
                }
            }
            break;
            
            case 'B': case 'b':
            {
                if (auctionstring[i - 1] == 'W' || auctionstring[i - 1] == 'w' ||
                    auctionstring[i - 1] == 'U' || auctionstring[i - 1] == 'u' ||
                   (auctionstring[i - 1] - '0' >= 0 && auctionstring[i - 1] - '0' <= 9))
                {
                    validString = true;
                } else
                {
                    return false;
                }
            }
            break;
                
            case '+':
            {
                if (auctionstring[i - 1] != 'B' && auctionstring[i - 1] != 'b')
                {
                    return false;
                }
            }
            break;
               
            case 'W': case 'w':
            {
                if (auctionstring[i - 1] == 'W' || auctionstring[i - 1] == 'w' ||
                    auctionstring[i - 1] == 'U' || auctionstring[i - 1] == 'u' ||
                   (auctionstring[i - 1] - '0' >= 0 && auctionstring[i - 1] - '0' <= 9))
                {
                    validString = true;
                } else
                {
                    return false;
                }
            }
            break;
                
            case 'U': case 'u':
            {
                if (auctionstring[i - 1] == 'W' || auctionstring[i - 1] == 'w' ||
                    auctionstring[i - 1] == 'U' || auctionstring[i - 1] == 'u' ||
                   (auctionstring[i - 1] - '0' >= 0 && auctionstring[i - 1] - '0' <= 9))
                {
                    validString = true;
                } else
                {
                    return false;
                }
            }
            break;
                
            default:
            {
                return false;
            }
        }
    }
    
    return validString;
}

bool listingSold(string auctionstring)              //determine if final bid is greater than list price
{
    int listPrice = getListing(auctionstring);
    int finalBid = totalBid(auctionstring);
    if (isValidEbayListingString(auctionstring))
    {
        if (finalBid > listPrice)
        {
            return true;
        }
    }
    return false;
}

int howMuch(string auctionstring)                       //returns final total bid
{
    if (isValidEbayListingString(auctionstring))
    {
        if (listingSold(auctionstring))
        {
            return totalBid(auctionstring);
        } else
        {
            return 0;
        }
    }
    return -1;
}

int watchers(string auctionstring)                  //check?
{
    int result = 0;
    if (isValidEbayListingString(auctionstring))
    {
        result = calcWatchers(auctionstring);
    } else
    {
        result = -1;
    }
    return result;
}

int number(string s, int& startingposition)     //returns valid int starting at "startingposition"
{
    int result = 0;
    if (s[startingposition] >= '1' &&
        s[startingposition] <= '9')
    {
        while (s[startingposition] >= '0' &&
               s[startingposition] <= '9')
        {
            int value = s[startingposition] - '0';
            result = (result * 10) + value;
            startingposition++;
        }
    } else
    {
        result = -1;
    }
    return(result);
}

int calcWatchers(string auctionstring)
{
    int result = 0;
    size_t length = auctionstring.length();
    bool firstWatch = true;                 //checks that first instance is NOT a 'U'
    for (size_t i = 0; i < length; i++)
    {
        if (auctionstring[i] == 'W' || auctionstring[i] == 'w')
        {
            result++;
            firstWatch = false;
        } else if (auctionstring[i] == 'U' || auctionstring[i] == 'u')
        {
            if (firstWatch)
            {
                return -1;
            }
            result--;
        }
        
        if (result < 0)
        {
            return -1;
        }
    }
    
    return result;
}

bool calcBids(string auctionstring)
{
    bool result = true;
    int countB = 0;
    size_t length = auctionstring.length();
    for (size_t i = 0; i < length; i++)
    {
        if (auctionstring[i] == 'B' || auctionstring[i] == 'b')
        {
            countB++;
            if (countB == 1 && auctionstring[i + 1] == '+')         //'B+' cannot occur on first iteration of 'B'
            {
                result = false;
                break;
            }
            
            if (countB > 1 && auctionstring[i + 1] != '+')          //opening bid 'B' can only occur once
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

int totalBid(string auctionstring)      //returns sum of all 'B' and 'B+' terms
{
    int total = 0;
    int indexB;
    for (int i = 0; i < auctionstring.length(); i++)
    {
        if (auctionstring[i] == 'B' || auctionstring[i] == 'b')
        {
            if (auctionstring[i + 1] == '+')
            {
                indexB = i + 2;
                total = total + number(auctionstring, indexB);
            } else
            {
                indexB = i + 1;
                total = total + number(auctionstring, indexB);
            }
        }
    }
    return total;
}

int getListing(string auctionstring)
{
    int priceL;
    int numL = 1;
    priceL = number(auctionstring, numL);
    return priceL;
}
