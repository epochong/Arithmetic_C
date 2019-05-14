#define _CRT_SECURE_NO_WARNINGS 1
#include <istream>
#include <iostream>
#include <string>
using namespace std;
char* add(string A, string B) {
		int asize = A.size() - 1;
		int bsize = B.size() - 1;
		char result[500] = { '\0' };
		char*p = result;
		char jinwei[500] = { '\0' };
		for (int i = 0; i < 500; i++) {
			result[i] = '\0';
			jinwei[i] = '\0';
		}
		jinwei[asize + 1] = '0' - 48;
		char t;
		for (int i = asize; i >= 0; i--) {
			if (bsize == -1) {
				result[i + 1] = A[asize--] - 48 + jinwei[i];
				for (int j = 0; j < i + 1; j++) {
					result[j] = A[j];
				}
				break; 
			}
			else {
				t = A[asize--] + B[bsize--] - 48 * 2 + jinwei[i + 1];
				result[i + 1] = t % 10;
				if (t / 10 == 0) {
					jinwei[i] = '0' - 48;
				}
				else {
					jinwei[i] = t / 10;
				}
			}
		}
		int i = 0;
		asize = A.size() - 1;
		bsize = B.size() - 1;
		if (result[0] == '\0') {
			for (i = 0; i < asize + 1; i++) {
				result[i] = result[i + 1] + 48;
			}
			if (i - 1 == asize) {
				result[i] = '\0';
			}
		}
		else {
			for (i = 0; i < asize + 2; i++) {
				result[i] += 48;
			}
		}

		return p;
}
int main() {
	string A;
	string B;
	cin >> A >> B;
	char *result;
	if (A.size() > B.size()) {
		result = add(A, B);
	}
	else {
		result = add(B, A);
	}
	int i = 0;
	int asize = A.size() - 1;
	for (i = 0; i < asize + 1; i++) {
		if (result[i] == '\0') {
			break;
		}
		else {
			cout << result[i];
		}
	}
	return 0;
}