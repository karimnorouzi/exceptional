#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;
struct Date
{
public:
    Date(){}

    auto operator ()() {return make_tuple(day, month, year);}
public:
    int day;
    int month;
    int year;

};

istream& operator>>(istream& stream, Date& date) {
    stream >> date.day >> date.month >> date.year ;
    return stream;
}

ostream& operator<<(ostream& stream, Date& date) {
    stream << date.day << date.month << date.year  << endl;
    return stream;
}



int main()
{
    vector<int> e;
    copy( istream_iterator<int>( cin ),  istream_iterator<int>(),  back_inserter( e ) );

    vector<int>::iterator first =  find( e.begin(), e.end(), 314 );

    vector<int>::iterator last = find( e.begin(), e.end(), 42 );
    *last = 0;

    copy( first,     last, ostream_iterator<int>( cout, "\n" ) );
    e.insert( --e.end(), 217 );
    copy( first, last, ostream_iterator<int>( cout, "\n"));

  return 0;
}
