// 4673 Self Number.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdio>
#include <set>
using namespace std;

set<int> s;

void dn(int n, int max) {
	if (n > max) {
		return;
	}

	int result = n;

	while (n > 0) {
		result += n % 10;
		n /= 10;
	}

	if (result > max) {
		return;
	}

	s.insert(result);

	return dn(result, max);
}

int main()
{
	int max = 10000;

	for (int i = 1; i < max; i++) {
		dn(i, max);
	}

	for (int i = 1; i < max; i++) {
		if (s.find(i) == s.end())
			printf("%d\n", i);
	}

    return 0;
}

