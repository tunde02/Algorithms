#include <iostream>
using namespace std;

int hour, minute;

int main() {
    cin >> hour >> minute;

    int alarm_hour;
    int alarm_minute;
    int minutes = (hour * 60 + minute) - 45;

    if(minutes < 0) {
        minutes += 1440;
    }

    alarm_hour = minutes / 60;
    alarm_minute = minutes % 60;

    cout << alarm_hour << " " << alarm_minute << endl;

    return 0;
}