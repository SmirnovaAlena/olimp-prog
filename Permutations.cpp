#include <iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s1, s2;
	if ((n < 4) && (n > 1)) {
		cout << "NO SOLUTION";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) {
				s1 += to_string(i) + " ";

			}
			else {
				s2 += to_string(i) + " ";
			}
		}
		cout << s1 << s2;
	}


	return 0;
}
