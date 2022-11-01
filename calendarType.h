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
    calendarType(int month, int year);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);
    void printCalendar();
};