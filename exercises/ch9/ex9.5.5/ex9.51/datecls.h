/*Write a class that has three unsigned members representing year,
  month, and day. Write a constructor that takes a string representing a date. Your
  constructor should handle a variety of date formats, such as January 1, 1900, 1/1/1900,
  Jan 1, 1900, and so on. */

#include <string>
#include <vector>
#include <vector>
#include <cctype>
#include <ostream>

using std::ostream;
using std::string;
using std::stoi;

class Date {
	public:
		Date() = default;
		Date(const string&);

		friend void month_day(const string&, Date&);
		friend std::ostream& print_date(ostream&,const Date&);
	private:
		unsigned year = 1999;
		unsigned month = 01;
		unsigned day = 01;
};

void month_day(const string &str, Date& curr) {
	if (isalnum(str[1])) {
		curr.day = stoi(string(str, 0, 1));
	} else {
		curr.day = stoi(string(1, str[0]));
	}
	string yer = str.substr(str.find_last_of(". /,") + 1);
	curr.year = stoi(yer);
}

std::ostream& print_date(ostream& os, const Date& dat) {
	os << "Day: " << dat.day << " Month: " << dat.month << " Year: " << dat.year;
	return os;
}



Date::Date(const string &s) {
	std::vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May",
				      "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	if (isalpha(s[0])) {
		string str(s, 0, 3);
		for (int i = 1; i <= 12; ++i) {
			if (str == months[i - 1]) {
				month = i;
				break;
			}
		}
		string rest = s.substr(s.find_first_of("0123456789"));
		month_day(rest, *this);
	} else {
		unsigned white = s.find_first_of("123456789");
		if (isalnum(s[white + 1])) {
			month = stoi(string(s, white, 2));
		} else {
			month = stoi(string(1, s[white]));
		}
		string rest2 = s.substr(s.find_first_of(" ,/") + 1);
		month_day(rest2, *this);
	}
}
