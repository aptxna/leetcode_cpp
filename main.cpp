#include <iostream>
#include <string>
#include "CountAndSay.h"

int main() {
	int n;
	cout << "please input n: ";
	cin >> n;
	CountAndSay nstr;
	cout << "the string is: " << nstr.countAndSay(n) << endl;
}
