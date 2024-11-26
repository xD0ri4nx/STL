#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Problema {
    string idProblema;
    string specializare;
    int durata;
};


struct Doctor {
    string idDoctor;
    string specializare;
    int timpDisponibil = 8;
    vector<string> problemeRezolvate;
};

int main() {
    ifstream inFile("input4_bonus.txt");
 
    int no_problems, no_doctors;
    vector<Problema> probleme;
    vector<Doctor> doctori;


    inFile >> no_problems;
    for (int i = 0; i < no_problems; ++i) {
        string id, speciality;
        int durata;
        inFile >> id >> speciality >> durata;
        probleme.push_back({ id, speciality, durata });
    }


    inFile >> no_doctors;
    for (int i = 0; i < no_doctors; ++i) {
        string id, speciality;
        inFile >> id >> speciality;
        doctori.push_back({ id, speciality });
    }


    for (const auto& problema : probleme) {

        auto doctor = find_if(doctori.begin(), doctori.end(), [&](Doctor& d) {
            return d.specializare == problema.specializare && d.timpDisponibil >= problema.durata;
            });


        if (doctor != doctori.end()) {
            doctor->timpDisponibil -= problema.durata;
            doctor->problemeRezolvate.push_back(problema.idProblema);
        }
    }


    for (const auto& doctor : doctori) {
        cout << doctor.idDoctor << " " << doctor.problemeRezolvate.size();
        for (const auto& idProblema : doctor.problemeRezolvate) {
            cout << " " << idProblema;
        }
        cout << endl;
    }

    return 0;
}