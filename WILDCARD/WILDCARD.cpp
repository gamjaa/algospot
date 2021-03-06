// WILDCARD.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string W, F;
int cache[101][101];

int match(int w, int f) {
	int& ret = cache[w][f];
	if (ret != -1)
		return ret;

	while (f < F.size() && w < W.size() && (W[w] == '?' || W[w] == F[f])) {
		++w; 
		++f;
	}

	if (w == W.size())
		return ret = (f == F.size());

	if (W[w] == '*') {
		for (int i = 0; f + i <= F.size(); i++) {
			if (match(w + 1, f + i))
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	int testcase;
	cin >> testcase;

	for (int times = 0; times < testcase; times++) {
		cin >> W;

		int N;	// 파일명 개수
		cin >> N;

		vector<string> answer;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, 101 * 101 * sizeof(int));
			cin >> F;
			if (match(0, 0))
				answer.push_back(F);
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}

	return 0;
}

