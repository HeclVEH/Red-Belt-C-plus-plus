#pragma once

#include <string>
using namespace std;

struct Date {
  int year, month, day;
};

struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};

ostream& operator<<(ostream& os, const Date& date);
istream& operator>>(istream& is, Date& date);
bool operator<(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator<=(const Date& d1, const Date& d2);
bool operator>(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);

ostream& operator<<(ostream& os, const Time& time);
istream& operator>>(istream& is, Time& time);
bool operator<(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator!=(const Time& t1, const Time& t2);
bool operator<=(const Time& t1, const Time& t2);
bool operator>(const Time& t1, const Time& t2);
bool operator>=(const Time& t1, const Time& t2);