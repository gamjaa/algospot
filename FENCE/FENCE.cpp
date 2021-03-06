#include <iostream>
#include <vector>
using namespace std;

int WIDTH;

int calc(vector<int>& fence, int fenceIndex) {
	int height = fence[fenceIndex];
	int size = 0;
	bool ok = false;

	for (int i = fenceIndex + 1; i < WIDTH; i++) {
		if (height > fence[i]) {
			break;
		}
		ok = true;
		size += height;
	}
	for (int i = fenceIndex - 1; i >= 0; i--) {
		if (height > fence[i]) {
			break;
		}
		ok = true;
		size += height;
	}

	return size + (ok ? height : 0);
}

int resolve(vector<int>& fence) {
	int result = 0;

	for (int i = 0; i < WIDTH; i++) {
		result = max(result, calc(fence, i));
	}

	return result;
}

int main(int argc, char* argv[]) {
	int testcase;
	cin >> testcase;

	for (int times = 0; times < testcase; times++) {
		cin >> WIDTH;
		vector<int> fence;

		for (int i = 0; i < WIDTH; i++) {
			int input;
			cin >> input;
			fence.push_back(input);
		}

		cout << resolve(fence) << endl;
	}

	return 0;
}