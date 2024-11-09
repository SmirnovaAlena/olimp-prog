#include <iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	long long k = 1;
	long long max = 0;
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] == s[i + 1]) {
			k++;

		}
		else {
			if (k > max) {
				max = k;
			}
			k = 1;
		}
	}
	cout << max;
	return 0;
}
