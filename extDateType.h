#include "dateType.h"

class extDateType : public dateType {

    private:

    string month;

    public:

    extDateType(int d = 1, int m = 1, int y = 1900);
    string getExtMonth();
    string printLongDate();
    string printLongMonthYear();

};
