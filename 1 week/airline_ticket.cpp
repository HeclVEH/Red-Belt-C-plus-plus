#include "airline_ticket.h"
#include <iomanip>

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << '-';
    os << setfill('0') << setw(2) << date.month << '-';
    os << setfill('0') << setw(2) << date.day;
    return os;
}

istream& operator>>(istream& is, Date& date) {
    string s_year, s_month;
    getline(is, s_year, '-');
    getline(is, s_month, '-');
    int day, month, year;
    is >> day;
    month = stoi(s_month);
    year = stoi(s_year);
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        throw invalid_argument("Invalid date: " + s_year + "-" + s_month + "-" + to_string(day));
    }
    date.year = year;
    date.month = month;
    date.day = day;
    return is;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << setfill('0') << setw(2) << time.hours << ':';
    os << setfill('0') << setw(2) << time.minutes;   
    return os;
}

istream& operator>>(istream& is, Time& time) {
    string s_hours;
    getline(is, s_hours, ':');    
    int hours, minutes;
    is >> minutes;
    hours = stoi(s_hours);
    if (hours < 0 || hours > 24 || minutes < 0 || minutes > 60) {
        throw invalid_argument("Invalid time: " + s_hours + ":" + to_string(minutes));
    }
    time.hours = hours;
    time.minutes = minutes;    
    return is;
}

bool operator<(const Time& t1, const Time& t2) {
    if (t1.hours < t2.hours)
        return true;

    if (t1.hours > t2.hours)
        return false;    

    return t1.minutes < t2.minutes;    
}

bool operator==(const Time& t1, const Time& t2) {
    return t1.hours == t2.hours && t1.minutes == t2.minutes;
}

bool operator!=(const Time& t1, const Time& t2) {
    return !(t1 == t2);
}

bool operator<=(const Time& t1, const Time& t2) {
    return (t1 < t2) || (t1 == t2);
}

bool operator>(const Time& t1, const Time& t2) {
    return (t1 != t2) && !(t1 < t2);
}

bool operator>=(const Time& t1, const Time& t2) {
    return (t1 > t2) || (t1 == t2);
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
