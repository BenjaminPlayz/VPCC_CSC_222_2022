#include <cassert>

#include "calendarType.h"

calendarType::calendarType(int month, int year) throw (calendarException) {
  try {
    firstDayOfMonth(month, year);
  } catch (dateType::invalidMonth im) {
    throw calendarException(im.what());
  } catch (dateType::invalidYear iy) {    
    throw calendarException(iy.what());
  }
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

int calendarType::getMonth() { return firstDate.getMonth(); }

void calendarType::setMonth(int month) {
  assert(month >= 1 && month <= 12);

  firstDate.setMonth(month);
}

int calendarType::getYear() { return firstDate.getYear(); }

void calendarType::setYear(int year) {
  assert(year >= 1900);

  firstDate.setYear(year);
}

void calendarType::printTitleAndColumns() {
  string title = firstDate.printLongMonthYear();
  int intialSpaces = (49 - title.length()) / 2;
  for (int i = 0; i < intialSpaces; i++) {
    cout << " ";
  }
  cout << title << endl;
  cout << "    "
       << "Sun"
       << "    "
       << "Mon"
       << "    "
       << "Tue"
       << "    "
       << "Wed"
       << "    "
       << "Thu"
       << "    "
       << "Fri"
       << "    "
       << "Sat" << endl;
}

void calendarType::printDayNumbers() {
  int dayIndex = 0;
  if (firstDay.getDay() == "Sunday") {
  } else if (firstDay.getDay() == "Monday") {
    dayIndex = 1;
  } else if (firstDay.getDay() == "Tuesday") {
    dayIndex = 2;
  } else if (firstDay.getDay() == "Wednesday") {
    dayIndex = 3;
  } else if (firstDay.getDay() == "Thursday") {
    dayIndex = 4;
  } else if (firstDay.getDay() == "Friday") {
    dayIndex = 5;
  } else if (firstDay.getDay() == "Saturday") {
    dayIndex = 6;
  }
  cout << "     ";
  bool first = true;
  for (int i = 1; i <= firstDate.numOfDaysForMonthYear(firstDate.getMonth(),
                                                       firstDate.getYear());
       i++) {
    if (first) {
      for (int j = 0; j < dayIndex; j++) {
        cout << "       ";
      }
      first = false;
    }
    if (dayIndex != 0 && dayIndex % 7 == 0) {
      cout << endl;
      cout << "     ";
    }
    if (i < 10) {
      cout << " " << i << "     ";
    } else {
      cout << i << "     ";
    }
    dayIndex++;
  }
}

void calendarType::printCalendar() {
  printTitleAndColumns();
  printDayNumbers();
}