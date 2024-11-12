#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Problema {
    string idProblema;
        string specializare;


};
struct Doctor
{
    string idDoctor;
    string specializare;
    bool ocupat = false;
};
int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    vector <Problema> probleme;
    vector <Doctor> doctori;
    inFile >> no_problems;

   for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        //cout << name << ' ' << speciality << '\n';
        probleme.emplace_back(name,speciality );
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        //cout << name << ' ' << speciality << '\n';
        doctori.emplace_back(name,speciality);
    }
      
    for (const auto& problema : probleme) {
        auto doctor = find_if(doctori.begin(), doctori.end(), [&](Doctor& doctor) {
            return doctor.specializare == problema.specializare && !doctor.ocupat;
            });

        if (doctor != doctori.end()) {
          
            doctor->ocupat = true;
            cout << doctor->idDoctor << " " << problema.specializare << std::endl;
        }
    }

   //for (auto problema : probleme)
   // for_each(probleme.begin(), probleme.end(), [&](Problema& probleme, Doctor& doctor) { if (probleme.specializare == doctor.specializare && doctor.ocupat=false) doctor.ocupat = true; })
   
  //  {
       // bool accepted = false;
       /* auto it = find_if(doctori.begin(), doctori.end(), [&](Doctor& doctor) { if (doctor.ocupat = true;)});
        if(problme.specializare==it.specializare)
            cout << problema.idProblema << "-Respins" << endl;
        else
            *///cout << problema.idProblema << "-Acceptat" << endl;
        /*for (auto doctor : doctori)
        {
            if (problema.specializare == doctor.specializare)
            {
                accepted = true;
                ocupat = true;
                break;
            }
            find_if(doctori.begin(), doctori.end(), [&](&doctor.ocupat == true;) { accepted = false;  })
        }
        if (accepted)
        {
            cout << problema.idProblema << "-Acceptat" << endl;

        }
        else
        {
            cout << problema.idProblema << "-Respins" << endl;

        }
    }*/
   /* find_if(doctori.begin(), doctori.end(), [&](&doctor.ocupat == true;) { accepted = false;  })
   
    
    
    
    
    {
        bool accepted = false;
        for (auto doctor : doctori)
        {
            if (problema.specializare == doctor.specializare)
            {
                accepted = true;
                break;
            }
        }
        if (accepted)
        {
            cout << problema.idProblema << "-Acceptat" << endl;

        }
        else
        {
            cout << problema.idProblema << "-Respins" << endl;

        }
    }*/

    return 0;
}