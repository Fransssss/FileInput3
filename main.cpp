// Author: Fransiskus Agapa
// 8/14/22

#include <iostream>
#include "string"
#include "fstream"                     // deal with file

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::ifstream;                  // file input
using std::string;

int main()
{
    cout << "\n== Happy Store Employee ==" << endl;
    cout << "1. Employee name" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    string choice;
    ifstream inFS;                       // input file stream
    cin >> choice;

    while(choice != "e" and choice != "E")
    {
        if(choice == "1")
        {
            cout << "\n= List of Employee =" << endl;
            inFS.open("employee.txt");
            if(inFS.is_open())
            {
                string employee;                                                          // get data for each line
                string name;
                string age;
                string gender;
                int numbering = 1;                                                        // number the list of people
                int posCommaOne;
                int posCommaTwo;
                int lengthAge;                                                             // length for age
                while(!inFS.eof())
                {
                    getline(inFS, employee);
                    posCommaOne = employee.find(',');                                   // find he first comma in a line
                    posCommaTwo = employee.find(',', posCommaOne + 1);             // find second comma in a line after the first comma
                    name = employee.substr(0,posCommaOne);
                    lengthAge = posCommaTwo - posCommaOne;
                    age = employee.substr(posCommaOne + 1, lengthAge - 1);         // +1 and -1 is to avoid commas
                    gender = employee.substr(posCommaTwo +1, employee.size() -1);  // +1 to avoid comma, -1 is to avoid out of range of string.length
                    cout << numbering << ". Name: " << name << endl;
                    cout << "   Age: " << age << endl;
                    cout << "   Gender: " << gender << endl << endl;
                    numbering++;                                                            // add number for next data/list of person
                }
                inFS.close();                                                               // close file so it can be used/opened later
            }
            else
            {
                cout << "\n[ File cannot be opened ]" << endl;                              // if something wrong happened
            }
        }
        else
        {
            cout << "\n[ Invalid choice ]" << endl;                                          // wrong user input
        }

        cout << "\n== Happy Store Employee ==" << endl;
        cout << "1. Employee name" << endl;
        cout << "e. Exit" << endl;
        cout << "choice: ";
        cin >> choice;
    }

    if(choice == "e" or choice == "E")
    {
        cout << "\n== Exit Program ==" << endl;
    }

    return 0;
}
