#include "calendarType.h"

int main() {
    int theMonth;
    int theYear;

    cout << "Enter month (as an integer between 1 and 12): ";
    cin >> theMonth;

    cout << "Enter year (as a 4-digit integer): ";
    cin >> theYear;

    calendarType calendar(theMonth, theYear);
    calendar.printCalendar();

    return 0;
}