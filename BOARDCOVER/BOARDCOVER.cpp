// BOARDCOVER.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int dx[8] = {-1, 0,		0, 1,		1, 1,		1, 0};
int dy[8] = {1, 1,		1, 1,		0, 1,		0, 1};
// ┘ └  ┐ ┌  

int countGame(int x, int y, int w, int h, bool game[20][20]) {
	if (game[x][y]) {
		if (x + dx[0] )
		if (game[x + dx[0]][y + dy[0]] && game[x + dx[1]][y + dy[1]]) {

		}

		if (game[x + dx[2]][y + dy[2]] && game[x + dx[3]][y + dy[3]]) {

		}

		if (game[x + dx[4]][y + dy[4]] && game[x + dx[5]][y + dy[5]]) {

		}

		if (game[x + dx[6]][y + dy[6]] && game[x + dx[7]][y + dy[7]]) {

		}
	}
}

int main()
{
	int cycle;
	cin >> cycle;

	for (int testCase = 0; testCase < cycle; testCase++) {
		memset(game, false, 20 * 20);

		int h, w;
		char c;
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++) {
			string line;
			getline(cin, line);
			for (int j = 0; j < w; j++) {
				if (line.at(j) == '.')
					game[i][j] = true;
			}
		}


	}

	return 0;
}

