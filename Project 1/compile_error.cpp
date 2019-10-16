
#include <iostream>
using namespace std;

int main()
{
    int surveyParticipants  //missing semicolon
                            //int preferDogs not declared
    int preferCats;
    
    cout << "How many students participated in this survey? ";
    cin >> surveyParticipants;
    cout << "How many students prefer a pet dog? ";
    cin >> preferDogs;
    cout << "How many students prefer a pet cat? ";
    cin >> preferCats;
    
    double pctDogs = 100.0 * preferDogs / surveyParticipants;
    double pctCats = 100.0 * preferCats / surveyParticipants;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << endl;
    cout << pctDogs << "% preferred dogs.  Ruff Ruff!" << endl;
    cout << pctCats << "% preferred cats.  Meow." << endl;
    
    if pctDogs > pctCats    //missing parentheses for true/false statement after "if"
    {
        cout << "It was more dogs than cats." << endl;
        
                            //missing closing bracket "}"
    else
    {
        cout << "It was more cats than dogs." << endl;
        
    }
    return(0);
}
