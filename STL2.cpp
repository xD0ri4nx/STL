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
        probleme.emplace_back(name,speciality );
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctori.emplace_back(name,speciality);
    }
      
    for (const auto& problema : probleme) {
        auto doctor = find_if(doctori.begin(), doctori.end(), [&](Doctor& doctor) {
            return doctor.specializare == problema.specializare && !doctor.ocupat;
            });

        if (doctor != doctori.end()) {
          
            doctor->ocupat = true;
            cout << doctor->idDoctor << " " << problema.idProblema << std::endl;
        }
    }

    return 0;
}