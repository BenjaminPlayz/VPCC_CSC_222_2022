#include "calendarType.h"
#include <stdexcept>

int main() {
  int theMonth;
  int theYear;

  string invalidInputStr = "invalid input";

  bool gettingInitialInput = true;
  while (gettingInitialInput) {
    try {
      cout << "Enter month (as an integer between 1 and 12): ";
      cin >> theMonth;

      if (!cin) {
        throw(invalidInputStr);
      }

      cout << "Enter year (as a 4-digit integer): ";
      cin >> theYear;

      if (!cin) {
        throw(invalidInputStr);
      }
    } catch (string errMsg) {
      cout << errMsg << endl;
      cout << "Restoring the input stream." << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
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
      try {
        cout << "Enter month (as an integer between 1 and 12): ";
        cin >> theMonth;

        if (!cin) {
          throw(invalidInputStr);
        }

        cout << "Enter year (as a 4-digit integer): ";
        cin >> theYear;

        if (!cin) {
          throw(invalidInputStr);
        }
      } catch (string errMsg) {
        cout << errMsg << endl;
        cout << "Restoring the input stream." << endl;
        cin.clear();
        cin.ignore(100, '\n');
      }
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