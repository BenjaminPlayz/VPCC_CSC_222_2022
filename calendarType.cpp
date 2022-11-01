#include "calendarType.h"

calendarType::calendarType (int month, int year) {
    firstDayOfMonth(month, year);
}

void calendarType::firstDayOfMonth(int month, int year) {
    firstDate = extDateType(1, month, year);
    int totalDays = 0;
    // total days in previous years
    for (int y = 1900; y < year; y++) {
        for (int m = 1; m <= 12; m++) {
            totalDays += firstDate.numOfDaysForMonthYear(m, y);
        }
    }
    // total days in previous months
    for (int m = 1; m < month; m++) {
        totalDays += firstDate.numOfDaysForMonthYear(m, year);
    }

//    cout << "totalDays: " << totalDays << endl;

    // Initialize to day of week for 1/1/1900
    firstDay.setDay("Monday");
    firstDay.setDay(firstDay.addDays(totalDays));

//    cout << "Day of week: " << firstDay.getDay() << endl;
}

int calendarType::getMonth() {
    return firstDate.getMonth();
}

void calendarType::setMonth(int month) {
    firstDate.setMonth(month);
}

int calendarType::getYear() {
    return firstDate.getYear();
}

void calendarType::setYear(int year) {
    firstDate.setYear(year);
}

void calendarType::printTitleAndColumns() {
    string title = firstDate.printLongMonthYear();
    int intialSpaces = (49 - title.length())/2;
    for (int i = 0; i < intialSpaces; i++) {
        cout << " ";
    }
    cout << title << endl;
    cout << "    " << "Sun" << "    " << "Mon" << "    " << "Tue" << "    " << "Wed" << "    " << "Thu" << "    " << "Fri" << "    " << "Sat" << endl;
}

void calendarType::printDayNumbers() {
    int intialSpaces = 0;
     int dayIndex = 0;
    if (firstDay.getDay() == "Sunday") {
        intialSpaces = 4;
    } else if (firstDay.getDay() == "Monday") {
        intialSpaces = 11;
        dayIndex = 1;
    } else if (firstDay.getDay() == "Tuesday") {
        intialSpaces = 18;
        dayIndex = 2;
    } else if (firstDay.getDay() == "Wednesday") {
        intialSpaces = 25;
        dayIndex = 3;
    } else if (firstDay.getDay() == "Thursday") {
        intialSpaces = 32;
        dayIndex = 4;
    } else if (firstDay.getDay() == "Friday") {
        intialSpaces = 39;
        dayIndex = 5;
    } else if (firstDay.getDay() == "Saturday") {
        intialSpaces = 46;
        dayIndex = 6;
    }
    for (int i = 0; i < intialSpaces; i++) {
        cout << " ";
    }
    cout << "  " << 1 << endl;
    bool first = true;
    for (int i = 1; i <= firstDate.numOfDaysForMonthYear(firstDate.getMonth(), firstDate.getYear()); i++) {
        if (first) {
            for (int j = 0; j < dayIndex; j++) {
                cout << "   ";
            }
            first = false;
        }
        if (dayIndex % 7 == 0) {
            cout << endl;
        }
        if (i < 10) {
            cout << " " << i << " ";
        } else {
            cout << i << " ";
        }
        dayIndex++;
    }
}

void calendarType::printCalendar() {
    printTitleAndColumns();
    printDayNumbers();
}