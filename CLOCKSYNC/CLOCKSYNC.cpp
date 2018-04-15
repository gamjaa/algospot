// CLOCKSYNC.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

const int BTN_COUNT = 10;
const vector<vector<int>> btn = {
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

const int CLOCK_COUNT = 16;
int clock[CLOCK_COUNT] = { 0, };
int click[16];

bool btnClick(int btnNum, int delta) {
	click[btnNum] += delta;
	delta *= 3;
	for (int i = 0; i < btn[btnNum].size(); i++) {
		clock[i] = (clock[btn[btnNum][i]] + delta + 12) % 12;
	}

	bool ok = true;
	for (int i = 0; i < CLOCK_COUNT; i++) {
		if (clock[i] != 0) {
			ok = false;
			break;
		}
	}
	return ok;
}

bool hasClock(int btnNum, int clockNum) {
	return find(btn[btnNum].begin(), btn[btnNum].end(), clockNum) != btn[btnNum].end();
}

int count() {
	int result = 0;
	for (int i = 0; i < BTN_COUNT; i++) {
		result += click[i];
	}
	return result;
}

int calc(vector<int>& answer) {
	for (int i = 0; i < CLOCK_COUNT; i++) {
		if (clock[i] != 0) {
			for (int j = 0; j < BTN_COUNT; j++) {
				if (click[j] < 3 && hasClock(j, i)) {
					if (btnClick(j, 1)) {
						answer.push_back(count());
					}
					btnClick(j, -1);
				}
			}
		}
	}
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int cycle = 0; cycle < testcase; cycle++) {
		for (int i = 0; i < CLOCK_COUNT; i++) {
			int time;
			cin >> time;
			if (time == 12)
				time = 0;
			clock[i] = time;
		}

		memset(click, 0, sizeof(int) * 16);

		vector<int> answer;
		calc(answer);

		int max = 0;
	}

    return 0;
}

