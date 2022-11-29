#include "dayType.h"
#include "extDateType.h"

class calendarType : public extDateType {
private:
  dayType firstDay;
  extDateType firstDate;
  void firstDayOfMonth(int month, int year);
  void printTitleAndColumns();
  void printDayNumbers();

public:
  class calendarException {
  public:
    calendarException(string msg) {
      message = msg;
    }
    string what() { return message; }

  private:
    string message;
  };
  calendarType(int month, int year) throw (calendarException);
  int getMonth();
  void setMonth(int month);
  int getYear();
  void setYear(int year);
  void printCalendar();
};