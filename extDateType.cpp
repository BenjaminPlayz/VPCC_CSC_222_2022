#include "extDateType.h"

string monthsOfTheYear[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

extDateType::extDateType(int d, int m, int y) : dateType(d, m, y) {
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

// int main() {

//     extDateType myDefaultDate;
//     cout << "Default constructor: " << myDefaultDate.printLongDate() << endl;
//     extDateType myExtDate(20,2,2003);
//     cout << "Constructor: " << myExtDate.printLongDate() << endl;
//     cout << "Number of days passed: " << myExtDate.numOfDaysPassed() << endl;
//     cout << "Number of days left: " << myExtDate.numOfDaysLeft() << endl;
//     cout << "Number of days in month: " << myExtDate.numOfDaysForMonthYear(myExtDate.getMonth(), myExtDate.getYear()) << endl;
//     myExtDate.addDays(15);
//     cout << "After 15 days, date will be: " << myExtDate.printLongDate() << endl;
//     myExtDate.setYear(2000);
//     cout << "Resetting year to 2000: " << myExtDate.getYear()  << endl;
//     cout << myExtDate.printLongDate() << endl;
//     myExtDate.setMonth(2);
//     cout << "Resetting month to 2: " << myExtDate.getMonth() << endl;
//     cout << myExtDate.printLongDate() << endl;
//     myExtDate.setDay(29);
//     cout << "Resetting day to 29: " << myExtDate.getDay() << endl;
//     cout << myExtDate.printLongDate() << endl;
//     cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
//     myExtDate.setYear(2001);
//     cout << "Resetting year to 2001: " << myExtDate.getYear()  << endl;
//     cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
//     myExtDate.setMonth(0);
//     cout << "Resetting month to 0: " << myExtDate.getMonth() << endl;
//     cout << "Number of days left: " << myExtDate.numOfDaysLeft() << endl;
//     cout << "Date is now set to: " << myExtDate.printLongDate() << endl;
//     myExtDate.addDays(1461);
//     cout << "After 1461 days, date will be: " << myExtDate.printLongDate() << endl;
//     return 0;
// }
