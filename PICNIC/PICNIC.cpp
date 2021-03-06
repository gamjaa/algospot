// PICNIC.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
bool isFriends[10][10];

int countTeam(int start, int remain, bool student[10]) {
	if (remain == 0)
		return 1;

	int result = 0;
	for (int i = start; i < 10; i++) {
		if (!student[i]) {
			for (int j = i+1; j < 10; j++) {
				if (isFriends[i][j] && !student[i] && !student[j]) {
					student[i] = true;
					student[j] = true;
					result += countTeam(i, remain - 1, student);
					student[i] = false;
					student[j] = false;
				}
			}
		}
	}

	return result;
}

int main()
{
	int cycle;
	cin >> cycle;

	// 테스트 케이스 반복
	for (int testCase = 0; testCase < cycle; testCase++) {
		memset(isFriends, false, 100);

		// 학생 수, 친구 수
		int studentCount, friendsCount;
		scanf_s("%d %d", &studentCount, &friendsCount);

		// 짝 입력
		for (int f = 0; f < friendsCount; f++) {
			int a, b;
			scanf_s("%d %d", &a, &b);
			isFriends[a][b] = true;
			isFriends[b][a] = true;
		}

		// 겹치지 않는 studentCount / 2 팀을 만들어야 함
		bool student[10] = { false };
		cout << countTeam(0, studentCount / 2, student) << endl;
	}

    return 0;
}

