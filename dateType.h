#ifndef H_dateType
#define H_dateType

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class dateType {
private:
  int dMonth;
  int dDay;
  int dYear;

public:
  class invalidYear {
  public:
    invalidYear() { message = "Invalid – year must be >= 1900"; }
    string what() { return message; }

  private:
    string message;
  };
  class invalidMonth {
  public:
    invalidMonth() { message = "Invalid – month must be between 1 and 12"; }
    string what() { return message; }

  private:
    string message;
  };
  class invalidDay {
  public:
    invalidDay(int max) {
      message = "Invalid – day must be between 1 and " + to_string(max);
    }
    string what() { return message; }

  private:
    string message;
  };
  dateType(int d = 1, int m = 1, int y = 1900) throw(invalidYear, invalidMonth);
  void setDate(int d, int m, int y) throw(invalidYear, invalidMonth,
                                          invalidDay);
  bool isLeapYear(int y);
  int numOfDaysForMonthYear(int m, int y);
  void setMonth(int m);
  void setDay(int d);
  void setYear(int y);
  int getMonth();
  int getDay();
  int getYear();
  string printDate();
  int numOfDaysPassed();
  int numOfDaysLeft();
  void addDays(int numofDaysToAdd);
};

#endif