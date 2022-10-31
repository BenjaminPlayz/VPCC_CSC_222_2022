#include <iostream>
#include <string>
using namespace std;

class dayType
{
private:
    string day;
    int dayIndex;
    string days_of_week[7];

    void initDaysOfWeek();

public:
    dayType();
    dayType(string theDay);

    string getDay();
    void setDay(string theDay);

    void printDay();
    string nextDay();
    string previousDay();
    string addDays(int numOfDaysToAdd);
};
