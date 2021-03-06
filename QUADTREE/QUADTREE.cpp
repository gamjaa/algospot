// QUADTREE.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}

	string s1 = reverse(it);
	string s2 = reverse(it);
	string s3 = reverse(it);
	string s4 = reverse(it);
	return string("x") + s3 + s4 + s1 + s2;
}

int main() {
	int testCase;
	cin >> testCase;

	for (int times = 0; times < testCase; times++) {
		string input;
		cin >> input;
		string::iterator it = input.begin();
		cout << reverse(it) << endl;
	}
}