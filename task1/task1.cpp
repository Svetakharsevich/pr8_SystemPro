
#include <iostream>
#include <string.h>
using namespace std;
struct Employee
{
    char surname [20];
    char gender [6];
    int SickLeave;
    union {
        struct {
            int phoneСlinic;
            char adress [30];
        } clinicInfo;

        bool FamilyStatus;
    } healInfo;
};

void Sorting(Employee arr[], int n) {
    for (int j = 0; j < n ; j++) {
        if (arr[j].surname > arr[j + 1].surname) {
            swap(arr[j], arr[j + 1]);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int sizes = 4;
    Employee employees[sizes] = {
        {"Харсевич", "women" , 20, true},
        {"Молотова", "women" , 40, 143040405, "ул.Ленина, д.23" },
        {"Иванович", "man" , 7, false},
        {"Гордый", "man" , 31, 143040405, "ул.Малышева, д.2"}

    };
    
    for (int i = 0; i < sizes; i++) {
       
        if (employees[i].gender == "man" || employees[i].healInfo.FamilyStatus == false) {
            cout << "Фамилия " << employees[i].surname << " Пол " << employees[i].gender << endl;
            if (employees[i].SickLeave > 21) {
                cout << "Номер поликлиники " << employees[i].healInfo.clinicInfo.phoneСlinic << endl;
                cout << "Адрес поликлиники " << employees[i].healInfo.clinicInfo.adress << endl;
            }
            else {
                cout << "Семейное положение " << employees[i].healInfo.FamilyStatus;
            }
            cout << " " << endl;
        }
       

    }

}
