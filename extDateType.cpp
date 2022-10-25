#include "extDateType.h"

// dateType::dateType(int d = 1, int m = 1, int y = 1900) {
//     setDate(d, m, y);
// }

// void dateType::setDate(int d, int m, int y) {
//     if (y >= 1900) {
//         dYear = y;
//     }
//     else {
//         dYear = 1900;
//     }
//     if (m >= 1 && m <= 12) {
//         dMonth = m;
//     }
//     else {
//         dMonth = 1;
//     }
//     if (d >= 1 && d <= numOfDaysForMonthYear(dMonth, dYear)) {
//         dDay = d;
//     }
//     else {
//         dDay = 1;
//     }
// }

// bool dateType::isLeapYear(int y) {
//     if (y % 400 == 0) {
//         return true;
//     }
//     else if (y % 100 == 0){
//         return false;
//     }
//     else if(y % 4 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int dateType::numOfDaysForMonthYear(int m, int y) {
//     if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
//        return 31;
//     }
//     else if (m == 4 || m == 6 || m == 9 || m == 11) {
//        return 30;
//     }
//     else if (m == 2) {
//         if (isLeapYear(y)) {
//             return 29;
//         } else {
//             return 28;
//         }
//     }
//     return 1;
// }

// void dateType::setMonth(int m) {
//     setDate(dDay, m, dYear);
// }

// void dateType::setDay(int d) {
//     setDate(d, dMonth, dYear);
// }

// void dateType::setYear(int y) {
//     setDate(dDay, dMonth, y);
// }

// int dateType::getMonth() {
//     return dMonth;
// }

// int dateType::getDay() {
//     return dDay;
// }    

// int dateType::getYear() {
//     return dYear;
// }

// string dateType::printDate() {
//     return to_string(dMonth) + "-" + to_string(dDay) + "-" + to_string(dYear);
// }

// int dateType::numOfDaysPassed() {
//     int numDays = 0;
//     for (int i = 1; i <= dMonth-1; i++) {
//         numDays += numOfDaysForMonthYear(i, dYear);
//     }
//     return numDays + dDay;
// }

// int dateType::numOfDaysLeft() {
//     return (isLeapYear(dYear) ? 366 : 365) - numOfDaysPassed();
// }

// void dateType::setDate(int numOfDaysToAdd) {
//     int numDaysTotal = numOfDaysPassed() + numOfDaysToAdd;
//     int m = 1;
//     int y = year;
//     while (numDaysTotal > numOfDaysForMonthYear(m, y)) {
//         numDaysTotal -= numOfDaysForMonthYear(m, y);
//         m++;
//     }
//     setMonth(m);
//     setDay(numDaysTotal);
// }

// void dateType::addDays(int numOfDaysToAdd) {
//     int numDaysTotal = numOfDaysPassed() + numOfDaysToAdd;
//     while (numDaysTotal > numOfDaysLeft()) {
//         setMonth(1);
//         setDay(1);
//         setYear(getYear()+1);
//         numDaysTotal = numDaysTotal - numOfDaysLeft() - 1;
//     }
//     int m = 1;
//     int y = dYear;
//     while (numDaysTotal > numOfDaysForMonthYear(m, y)) {
//         numDaysTotal -= numOfDaysForMonthYear(m, y);
//         m++;
//     }
//     setMonth(m);
//     setDay(numDaysTotal);
// }

// class extDateType : public dateType {

//     private:

//     string month;

//     public:

//     extDateType(int x, int y, int z);
//     string getExtMonth();
//     string printLongDate();
//     string printLongMonthYear();

// };

string monthsOfTheYear[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

extDateType::extDateType(int d = 1, int m = 1, int y = 1900) : dateType(d, m, y) {
    month = monthsOfTheYear[getMonth()];
}

string extDateType::getExtMonth() {
    return monthsOfTheYear[getMonth()];
}

string extDateType::printLongDate () {
    return getExtMonth() + " " + to_string(getDay()) + ", " + to_string(getYear());
}

string extDateType::printLongMonthYear () {
    return getExtMonth() + " " + to_string(getYear());
}

int main(){

    extDateType myDefaultDate;
    cout << "Default constructor: " << myDefaultDate.printLongDate() << endl;
    extDateType myExtDate(20,2,2003);
    cout << "Constructor: " << myExtDate.printLongDate() << endl;
    cout << "Number of days passed: " << myExtDate.numOfDaysPassed() << endl;
    cout << "Number of days left: " << myExtDate.numOfDaysLeft() << endl;
    cout << "Number of days in month: " << myExtDate.numOfDaysForMonthYear(myExtDate.getMonth(), myExtDate.getYear()) << endl;
    myExtDate.addDays(15);
    cout << "After 15 days, date will be: " << myExtDate.printLongDate() << endl;
    myExtDate.setYear(2000);
    cout << "Resetting year to 2000: " << myExtDate.getYear()  << endl;
    cout << myExtDate.printLongDate() << endl;
    myExtDate.setMonth(2);
    cout << "Resetting month to 2: " << myExtDate.getMonth() << endl;
    cout << myExtDate.printLongDate() << endl;
    myExtDate.setDay(29);
    cout << "Resetting day to 29: " << myExtDate.getDay() << endl;
    cout << myExtDate.printLongDate() << endl;
    cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
    myExtDate.setYear(2001);
    cout << "Resetting year to 2001: " << myExtDate.getYear()  << endl;
    cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
    myExtDate.setMonth(0);
    cout << "Resetting month to 0: " << myExtDate.getMonth() << endl;
    cout << "Number of days left: " << myExtDate.numOfDaysLeft() << endl;
    cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
    myExtDate.addDays(1461);
    cout << "After 1461 days, date will be: " << myExtDate.printLongDate() << endl;
    return 0;
}
