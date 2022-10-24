#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dateType {
private:
int year;
int month;
int day;

public:
dateType(int x = 1, int y = 1, int z = 1900) {
    setDate(x, y, z);
}

void setDate(int d, int m, int y) {
    if (y >= 1900) {
        year = y;
    }
    else {
        year = 1900;
    }
    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        month = 1;
    }
    if (d >= 1 && d <= numOfDaysForMonthYear(month, year)) {
        day = d;
    }
    else {
        day = 1;
    }
}

bool isLeapYear(int y) {
    if (y % 400 == 0) {
        return true;
    }
    else if (y % 100 == 0){
        return false;
    }
    else if(y % 4 == 0){
        return true;
    }
    else{
        return false;
    }
}

int numOfDaysForMonthYear(int m, int y) {
    if (m == 1 || m == 4 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
       return 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
       return 30;
    }
    else if (m == 2) {
        if (isLeapYear(y)) {
            return 29;
        } else {
            return 28;
        }
    }
    return 1;
}

void getDate() {
cout << month << "-" << day << "-" << year << endl;
}

void setMonth(int x) {
    month = x;
}

void setDay(int x) {
    day = x;
}

void setYear(int x) {
    year = x;
}

int getMonth() {
    return month;
}

int getDay() {
    return day;
}

int getYear() {
    return year;
}

string printDate() {
    return to_string(month) + "-" + to_string(day) + "-" + to_string(year);
}

int numOfDaysPassed() {
    int numDays = 0;
    for (int i = 1; i <= month-1; i++) {
        numDays += numOfDaysForMonthYear(i, year);
    }
    return numDays + day;
}

int numOfDaysLeft() {
    return (isLeapYear(year) ? 366 : 365) - numOfDaysPassed();
}


};

int main(){

    dateType myDefaultDate;
    cout << "Default constructor: " << myDefaultDate.printDate() << endl;
    dateType myDate(20,2,2003);
    cout << "Constructor: " << myDate.printDate() << endl;
    cout << "Number of days passed: " << myDate.numOfDaysPassed() << endl;
    cout << "Number of days left: " << myDate.numOfDaysLeft() << endl;
    cout << "Number of days in month: " << myDate.numOfDaysForMonthYear(myDate.getMonth(), myDate.getYear()) << endl;
    return 0;
}