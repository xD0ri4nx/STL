#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Problema {
    string idProblema;
    string specializare;
    int durata;
    int prioritate;
};


struct ComparaProblema {
    bool operator()(const Problema& a, const Problema& b) {
        return a.prioritate < b.prioritate;
    }
};

struct Doctor {
    string idDoctor;
    string specializare;
    int timpDisponibil = 8;
    vector<string> problemeRezolvate;
};

int main() {
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    priority_queue<Problema, vector<Problema>, ComparaProblema> probleme;
    vector<Doctor> doctori;


    inFile >> no_problems;
    for (int i = 0; i < no_problems; ++i) {
        string id, speciality;
        int durata, prioritate;
        inFile >> id >> speciality >> durata >> prioritate;
        probleme.push({ id, speciality, durata, prioritate });
    }


    inFile >> no_doctors;
    for (int i = 0; i < no_doctors; ++i) {
        string id, speciality;
        inFile >> id >> speciality;
        doctori.push_back({ id, speciality });
    }


    while (!probleme.empty()) {
        auto problema = probleme.top();
        probleme.pop();
        auto doctor = find_if(doctori.begin(), doctori.end(), [&](Doctor& d) {
            return d.specializare == problema.specializare && d.timpDisponibil >= problema.durata;
            });

        if (doctor != doctori.end()) {
            doctor->timpDisponibil -= problema.durata;
            doctor->problemeRezolvate.push_back(problema.idProblema);
        }
    }


    for (const auto& doctor : doctori) {
        if (!doctor.problemeRezolvate.empty()) {
            cout << doctor.idDoctor << " " << doctor.problemeRezolvate.size();
            for (const auto& idProblema : doctor.problemeRezolvate) {
                cout << " " << idProblema;
            }
            cout << endl;
        }
    }

    return 0;
}