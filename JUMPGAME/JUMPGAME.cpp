// JUMPGAME.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int game[100][100], cache[100][100];

int solve(int y, int x, int n) {
	if (y >= n || x >= n)
		return 0;
	int d = game[y][x];
	if (d == 0)
		return 1;
	int& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}
	ret = solve(y + d, x, n) || solve(y, x + d, n) ? 1 : 0;
	return ret;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int times = 0; times < testcase; times++) {
		memset(game, -1, sizeof(int) * 100 * 100);
		memset(cache, -1, sizeof(int) * 100 * 100);
		int n;
		cin >> n;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> game[y][x];
			}
		}
		const char* result = (solve(0, 0, n) > 0) ? "YES" : "NO";
		cout << result << endl;
	}

    return 0;
}

