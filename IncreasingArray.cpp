#include<iostream>
#include<string>
using namespace std;
int main() {
	long n;
	cin >> n;
	long a = 0;
	long b;
	long sum = 0;
	for (long i = 0; i < n; i++) {
		b = a;
		cin >> a;
		if (a < b) {
			sum += b - a;
			a = a + (b - a);
		}
	}
	cout << sum;
	return 0;
}
