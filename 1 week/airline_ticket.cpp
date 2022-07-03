#include "airline_ticket.h"
#include <iomanip>

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << '-';
    os << setfill('0') << setw(2) << date.month << '-';
    os << setfill('0') << setw(2) << date.day;

    return os;
}

bool operator<(const Date& d1, const Date& d2) {
    if (d1.year < d2.year)
        return true;

    if (d1.year > d2.year)
        return false;

    if (d1.month > d2.month)
        return false;

    if (d1.month < d2.month)
        return true;

    return d1.day < d2.day;
}

bool operator==(const Date& d1, const Date& d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator!=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}

bool operator<=(const Date& d1, const Date& d2) {
    return (d1 < d2) || (d1 == d2);
}

bool operator>(const Date& d1, const Date& d2) {
    return (d1 != d2) && !(d1 < d2);
}

bool operator>=(const Date& d1, const Date& d2) {
    return (d1 > d2) || (d1 == d2);
}
