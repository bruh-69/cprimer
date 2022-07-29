/* write a program that finds each numeric character and then each alpha-
	betic character in the string "ab2c3d7R4E6". Write two versions of the program.
	The first should use find_first_of, and the second find_first_not_of. */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void of_charfind(string& str) {
	string nums("0123456789");

	cout << "FINDING NUMS: " << endl;
	for (string::size_type pos = 0; (pos = str.find_first_of(nums, pos)) != string::npos; ++pos) {
		cout << "the number: " << str[pos] << endl;
		cout << "has been found at position: " << pos << endl;
	}
	cout << "\nFINDING CHARS: " << endl;
	for (string::size_type pos2 = 0; (pos2 = str.find_first_not_of(nums, pos2)) != string::npos; ++pos2) {
		cout << "the char: " << str[pos2] << endl;
		cout << "has been found at position: " << pos2 << endl;
	}

}

void not_of_charfind(string& str) {
	string nums("0123456789");
	cout << "FINDING NUMS: " << endl;
	for (string::size_type pos = 0; (pos = str.find_first_not_of(nums, pos)) != string::npos; ++pos) {
		cout << "the number: " << str[pos] << endl;
		cout << "has been found at position: " << pos << endl;
	}
	cout << "\nFINDING CHARS: " << endl;
	for (string::size_type pos2 = 0; (pos2 = str.find_first_of(nums, pos2)) != string::npos; ++pos2) {
		cout << "the char: " << str[pos2] << endl;
		cout << "has been found at position: " << pos2 << endl;
	}
}

int main()
{
	string str("ab2c3d7R4E6");
	
	cout << "chars and nums with positions using find_first_of: " << endl;
	of_charfind(str);
	cout << "chars and nums with positions using find_first_not_of: " << endl;
	not_of_charfind(str);
	return 0;
}	
