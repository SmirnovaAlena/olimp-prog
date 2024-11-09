#include <iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;

	long long a;
	long long sum = 0;
	for (long long i = 0; i < n - 1; i++) {
		cin >> a;
		sum += a;
	}
	cout << n * (n + 1) / 2 - sum;


	return 0;
}
