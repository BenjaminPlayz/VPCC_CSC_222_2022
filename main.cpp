<<<<<<< HEAD
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
    cout << endl;

    char answer;
    bool done = false;
    while (!done) {
        cout << "Print another calendar (y or n)? ";
        cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }
 
        cout << "Enter month (as an integer between 1 and 12): ";
        cin >> theMonth;

        cout << "Enter year (as a 4-digit integer): ";
        cin >> theYear;

        calendarType calendar(theMonth, theYear);
        calendar.printCalendar();
        cout << endl;
    }


=======
#include "dateType.h"

int main(){

    dateType myDefaultDate;
    cout << "Default constructor: " << myDefaultDate.printDate() << endl;
    dateType myDate(20,2,2003);
    cout << "Constructor: " << myDate.printDate() << endl;
    dateType myBadDate(40,2,2003);
    cout << "Constructor: " << myBadDate.printDate() << endl;
>>>>>>> dateType_v2
    return 0;
}