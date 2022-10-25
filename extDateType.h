#include "dateType.h"

class extDateType : public dateType {

    private:

    string month;

    public:

    extDateType(int x, int y, int z);
    string getExtMonth();
    string printLongDate();
    string printLongMonthYear();

};
