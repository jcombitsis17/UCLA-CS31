//Jordan Combitsis
//UID: 004-921-527

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int findMinimum(const string array[], int n);
int countAllPunctuation(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
int removeDuplicatedValues(string array[], int n);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);
int shiftRight(string array[], int n, int amount, string placeholder);

int main()
{
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard.", "-cersei,"};
    string punct[10] = {".", ",", "!", ";", "'", "-", "/", ":", "?", "\""};
    string floats[4] = {"4.4.3.3", "44", "33.098", "33.098a"};
    string numbers[4] = {".045", "0.0002", "50", "76."};
    string data[4] = {"happy", "days", "are here", "again"};
    string integers[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    
    assert(findMinimum(people, 5) == 3);
    assert(findMinimum(people, 3) == 1);
    assert(findMinimum(folks, 8) == 7);
    assert(findMinimum(people, 0) == -1);
    
    assert(countAllPunctuation(punct, 10) == 10);
    assert(countAllPunctuation(folks, 8) == 3);
    assert(countAllPunctuation(punct, -3) == -1);
    
    assert(countFloatingPointValues(floats, 4) == 2);
    assert(countFloatingPointValues(numbers, 4) == 4);
    assert(countFloatingPointValues(punct, 10) == 0);
    assert(countFloatingPointValues(folks, 8) == 0);
    assert(countFloatingPointValues(floats, -10000) == -1);
    
    string duplicates[10] = {"happy", "Friday", "happy", "apple", "black",
                             "panther", "black", "happy", "panther", "hello"};
    assert(removeDuplicatedValues(duplicates, 10) == 4);
    assert(removeDuplicatedValues(duplicates, 0) == -1);
    
    assert(replaceAll(data, 4, 'a', 'z') == 5);
    assert(replaceAll(data, 4, 'q', 'p') == 0);
    assert(replaceAll(data, -1, 'g', 'b') == -1);
    
    assert(shiftRight(people, 5, 8, "foo") == 5);
    assert(shiftRight(integers, 10, 7, "foo") == 7);
    assert(shiftRight(integers, -5, 3, "AAAA") == -1);
    assert(shiftRight(integers, 8, 0, "HA7") == 0);
    assert(shiftRight(integers, 10, -1, "blah") == -1);
    
    cerr << "All tests passed!" << endl << endl;
    
    cerr << "duplicates[10] = {";
    for (int i = 0; i < 10; i++)
    {
        cerr << "\"" << duplicates[i] << "\"";
        if (i != 9)
            cerr << ", ";
        else
            cerr << "};" << endl << endl;
    }
    
    cerr << "data[4] = {";
    for (int i = 0; i < 4; i++)
    {
        cerr << "\"" << data[i] << "\"";
        if (i != 3)
            cerr << ", ";
        else
            cerr << "};" << endl << endl;
    }
    
    cerr << "integers[10] = {";
    for (int i = 0; i < 10; i++)
    {
        cerr << "\"" << integers[i] << "\"";
        if (i == 9)
            cerr << "};" << endl << endl;
        else
            cerr << ", ";
    }
}

int findMinimum(const string array[], int n)
{
    if (n <= 0)
        return -1;
    
    int min = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        string one = array[min];
        string two = array[i + 1];

        if (one != two)
        {
            if (one < two)
            {
                min = i;
            }
            else
            {
                min = i + 1;
            }
        }
    }
    
    return min;
}

int countAllPunctuation(const string array[], int n)
{
    if (n <= 0)
        return -1;
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string s = array[i];
        for (int j = 0; j < s.length(); j++)
        {
            char c = s[j];
            if (c == '.' || c == ',' || c == '!' || c == ';' || c == '\'' ||
                c == '-' || c == '/' || c == ':' || c == '?' || c == '"')
            {
                count++;
            }
        }
    }
    return count;
}

int countFloatingPointValues(const string array[], int n)
{
    if (n <= 0)
        return -1;
    
    int floats = 0;
    for (int i = 0; i < n; i++)
    {
        bool validFloat = true;
        string s = array[i];
        int decimal = 0;
        
        if (s == ".")
            continue;
        
        for (int j = 0; j < s.length(); j++)
        {
            char c = s[j];
            if (c != '.' && (c < '0' || c > '9'))
            {
                validFloat = false;
            } else if (c == '.')
            {
                decimal++;
            }
        }
        
        if (validFloat && (decimal == 0 || decimal == 1))
        {
            floats++;
        }
    }
    return floats;
}

int removeDuplicatedValues(string array[], int n)
{
    if (n <= 0)
        return -1;
    
    int duplicates = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (array[i] != "" && array[i] == array[j])
            {
                duplicates++;
                array[j] = "";
            }
        }
    }
    
    for (int k = 0; k < (n - duplicates); k++)  //(n - duplicates) to avoid infinite loop on the k-- below
    {
        if (array[k] == "")             //if empty string found...send to back of array
        {
            for (int l = k; l < (n - 1); l++)
            {
                string temp = array[l + 1];
                array[l + 1] = array[l];
                array[l] = temp;
            }
            k--;                        //check the spot that was switched for a second time
        }
    }
    return duplicates;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
    if (n <= 0)
        return -1;
    
    int replaced = 0;
    for (int i = 0; i < n; i++)
    {
        string s = array[i];
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == letterToReplace)
            {
                s[j] = letterToFill;
                replaced++;
            }
        }
        array[i] = s;
    }
    return replaced;
}

int shiftRight(string array[], int n, int amount, string placeholder)
{
    if (n <= 0 || amount < 0)
        return -1;
    
    if (amount > n)
        amount = n;
    
    for (int i = (n - 1); i >= amount; i--)
    {
        array[i] = array[i - amount];
    }
    
    for (int j = 0; j < amount; j++)
    {
        array[j] = placeholder;
    }
    
    return amount;
}
