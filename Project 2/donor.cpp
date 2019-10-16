//Jordan Combitsis
//UID: 004-921-527

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    string gender;
    int age;
    int weight;
    int height;
    bool validDonor = false;
    
    cout << "Donor name: ";
    getline(cin, name);
    if (name == "")
    {
        cout << "--- You must enter a valid name." << endl;
        return(1);
    }
    
    cout << "Gender: ";
    getline(cin, gender);
    if (gender == "" || (gender != "Male" && gender != "Female" && gender != "Trans Male" && gender != "Trans Female" && gender != "Queer" && gender != "Different"))
    {
        cout << "--- You must enter a valid gender." << endl;
        return(2);
    }
    
    cout << "Age: ";
    cin >> age;
    if (age < 0)
    {
        cout << "--- You must enter a valid age." << endl;
        return(3);
    }
    
    cout << "Weight: ";
    cin >> weight;
    if (weight < 0)
    {
        cout << "--- You must enter a valid weight." << endl;
        return(4);
    }
    
    cout << "Height: ";
    cin >> height;
    if (height < 0)
    {
        cout << "--- You must enter a valid height." << endl;
        return(5);
    }
    
    if (weight >= 110)
    {
        if (age >= 23)
        {
            validDonor = true;
        } else if (age >= 16 && age <= 22)
        {
            if (height >= 60 && (gender == "Male" || gender == "Female"))
            {
                validDonor = true;
            }
            
            if (gender == "Female")
            {
                if (height == 58 && weight >= 146)
                {
                    validDonor = true;
                } else if (height == 59 && weight >= 142)
                {
                    validDonor = true;
                }
            }
        }
    }
    
    if (validDonor == true)
    {
        cout << "--- Yes, " << name << " you can donate blood." << endl;
    } else
    {
        cout << "--- No, " << name << " you cannot donate blood." << endl;
    }
    
    return(0);
}
