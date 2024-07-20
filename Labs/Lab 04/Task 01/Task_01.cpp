#include <iostream>
#include <vector>
#include "Priority_Queue_Dec.h"
using namespace std;

class Patient
{
public:
    string name;
    string disorder;
    string registrationNo;
    int severity;

    Patient(string n, string d, string rNo, int sev) : name(n), disorder(d), registrationNo(rNo), severity(sev) {}
    friend class EmergencyRoom;
};

class EmergencyRoom
{
    Queue erQueue;

public:
    vector<Patient> v;

    void addPatient(const Patient &patient)
    {
        v.push_back(patient);
        erQueue.enqueue(patient.severity, patient.name);
    }
    Patient treatNextPatient()
    {
        if (erQueue.size() == 0)
        {
            cout << "Empty Queue" << endl;
            return Patient("", "", "", -923);
        }
        else
        {
            pair<int, string> p = erQueue.dequeue();
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].name == p.second)
                    return v[i];
            }
            return Patient("", "", "", -923);
        }
    }
    bool hasPatients()
    {
        return erQueue.size() > 0;
    }

    void displayAllPatients()
    {
        while (hasPatients())
        {
            int c = 1;
            pair<int, string> p = erQueue.dequeue();
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].name == p.second)
                {
                    cout << "Patient : " << c++ << endl;
                    cout << "Name : " << v[i].name << endl;
                    cout << "Disorder : " << v[i].disorder << endl;
                    cout << "Registration No : " << v[i].registrationNo << endl;
                    cout << "Severity : " << v[i].severity << endl;
                    cout << endl;
                }
            }
        }
    }
};

int main()
{
    string name, rNo, dis;
    int sev;
    EmergencyRoom ER;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << endl;
        getline(cin, name);
        getline(cin, dis);
        getline(cin, rNo);
        cin >> sev;
        cin.ignore();
        Patient p(name, dis, rNo, sev);
        ER.addPatient(p);
        cout << endl;
    }

    Patient p2 = ER.treatNextPatient();
    cout << "Name : " << p2.name << endl;
    cout << "Disorder : " << p2.disorder << endl;
    cout << "Registration No : " << p2.registrationNo << endl;
    cout << "Severity : " << p2.severity << endl;
    cout << endl;
    
    ER.displayAllPatients();
    ER.hasPatients();

    return 0;
}