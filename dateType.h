#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dateType {
private:
int dMonth;
int dDay;
int dYear;

public:
    dateType(int x, int y, int z);
    void setDate(int d, int m, int y);
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
    void setDate(int numofDaysToAdd);
};
