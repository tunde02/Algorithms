#include <iostream>
#include <math.h>
using namespace std;

int t, students;
float result;

int main() {
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> students;
        int scores[students] = {0};
        int sum = 0, avg = 0, upperStudents = 0;

        for(int j=0; j<students; j++) {
            cin >> scores[j];
            sum += scores[j];
        }

        avg = sum / students;

        for(int j=0; j<students; j++) {
            upperStudents = scores[j] > avg ? upperStudents + 1 : upperStudents;
        }

        result = ((float)upperStudents) / students;

        cout.setf(ios::fixed);
        cout.precision(3);
        cout << round(result * 100000) / 1000 << "%\n";
    }
}