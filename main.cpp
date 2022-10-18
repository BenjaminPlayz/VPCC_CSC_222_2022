#include <iostream>
#include <string>
using namespace std;

class dayType
{
private:
    string day;
    int dayIndex;
    string days_of_week[7];

    void initDaysOfWeek();

public:
    dayType();
    dayType(string theDay);

    string getDay();
    void setDay(string theDay);

    void printDay();
    string nextDay();
    string previousDay();
    string addDays(int numOfDaysToAdd);
};

void dayType::initDaysOfWeek() {
    days_of_week[0] = "Sunday";
    days_of_week[1] = "Monday";
    days_of_week[2] = "Tuesday";
    days_of_week[3] = "Wednesday";
    days_of_week[4] = "Thursday";
    days_of_week[5] = "Friday";
    days_of_week[6] = "Saturday";
}

dayType::dayType() {
    initDaysOfWeek();
    day = days_of_week[0];
    dayIndex = 0;
}

dayType::dayType(string theDay) {
    initDaysOfWeek();
    setDay(theDay);
}

string dayType::getDay()  {
    return day;
}

void dayType::setDay(string theDay)  {
    bool found = false;
    for (int i=0; i<7; i++) {
        if (theDay == days_of_week[i]) {
            found = true;
            dayIndex = i;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: invalid day: " << theDay << endl;
    } else {
        day = theDay;
    }
}

void dayType::printDay() {
    cout << day << endl;
}

string dayType::nextDay() {
    int nextDayIndex;
    if (dayIndex == 6) {
        nextDayIndex = 0;
    } else {
        nextDayIndex = dayIndex + 1;
    }
    return days_of_week[nextDayIndex];
}

string dayType::previousDay() {
    int prevDayIndex;
    if (dayIndex == 0) {
        prevDayIndex = 6;
    } else {
        prevDayIndex = dayIndex - 1;
    }
    return days_of_week[prevDayIndex];
}

string dayType::addDays(int numOfDaysToAdd) {
    dayIndex = (dayIndex + numOfDaysToAdd)%7;
    day = days_of_week[dayIndex];
    return day;
}

int main() {
    dayType mySunday;
    cout << "From default constructor: ";
    mySunday.printDay();
    cout << "Next day: " << mySunday.nextDay() << endl;
    cout << "Previous day: " << mySunday.previousDay() << endl;
    dayType myMonday("Monday");
    cout << "From constructor with parameters: ";
    myMonday.printDay();
    cout << "After adding 3 days: " << myMonday.addDays(3) << endl;
    cout << "After adding 30 days: " << myMonday.addDays(30) << endl;
    cout << "After adding 365 days: " << myMonday.addDays(365) << endl;
    return 0;
}