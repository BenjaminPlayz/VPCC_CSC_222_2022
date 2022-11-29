#include "calendarType.h"

int main() {
    int theMonth;
    int theYear;

    bool gettingInitialInput = true;
    while (gettingInitialInput) {
        cout << "Enter month (as an integer between 1 and 12): ";
        cin >> theMonth;

        cout << "Enter year (as a 4-digit integer): ";
        cin >> theYear;
        try {
            calendarType calendar(theMonth, theYear);
            calendar.printCalendar();
            cout << endl;
            gettingInitialInput = false;
        } catch (calendarType::calendarException ce) {
            cout << ce.what() << endl;
            cout << "Please try again with valid input" << endl;
            cout << endl;
        }
    }
    cout << endl;

    char answer;
    bool done = false;
    while (!done) {
        cout << "Print another calendar (y or n)? ";
        cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }

        bool gettingMoreInput = true;
        while (gettingMoreInput) {
            cout << "Enter month (as an integer between 1 and 12): ";
            cin >> theMonth;

            cout << "Enter year (as a 4-digit integer): ";
            cin >> theYear;
            try {
                calendarType calendar(theMonth, theYear);
                calendar.printCalendar();
                cout << endl;
                gettingMoreInput = false;
            } catch (calendarType::calendarException ce) {
                cout << ce.what() << endl;
                cout << "Please try again with valid input" << endl;
                cout << endl;
            }
        }
        cout << endl;
    }


    return 0;
}