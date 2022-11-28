#include "dateType.h"

int main(){

    dateType myDefaultDate;
    cout << "Default constructor: " << myDefaultDate.printDate() << endl;
    dateType myDate(20,2,2003);
    cout << "Constructor: " << myDate.printDate() << endl;
    dateType myBadDate(40,2,2003);
    cout << "Constructor: " << myBadDate.printDate() << endl;
    return 0;
}