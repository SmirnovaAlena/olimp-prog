#include<iostream>
#include<vector>
#include<string>
using namespace std;
unsigned long long up(unsigned long long** ar, unsigned long long last, unsigned long long i) {
	last++;
	double middle = (last + ((i + 1) * (i + 1))) / 2;
	unsigned long long x = 0;
	while (last != middle) {
		ar[i][x] = last;
		last++; x++;
	}
	while (last != (i + 1) * (i + 1) + 1) {
		ar[x][i] = last;
		last++; x--;
	}
	return last - 1;
}
unsigned long long read(unsigned long long n, vector<unsigned long long>* v) {
	unsigned long long x, y;
	unsigned long long maxx = 0;
	for (unsigned long long i = 0; i < n; i++) {
		cin >> x >> y;
		v->push_back(x); v->push_back(y);
		if (max(x, y) > maxx) {
			maxx = max(x, y);
		}
	}
	return maxx;
}
unsigned long long down(unsigned long long** ar, unsigned long long last, unsigned long long i) {
	last++;
	double middle = (last + ((i + 1) * (i + 1))) / 2;
	unsigned long long x = 0;
	while (last != middle) {
		ar[x][i] = last;
		last++; x++;
	}
	while (last != (i + 1) * (i + 1) + 1) {
		ar[i][x] = last;
		last++; x--;
	}
	return last - 1;
}
void fill(unsigned long long m, unsigned long long** ar) {
	for (unsigned long long i = 0; i < m; i++) {
		ar[i] = new unsigned long long[m];
	}
	unsigned long long last = 1;
	ar[0][0] = 1;
	for (unsigned long long i = 1; i < m; i++) {
		if (i % 2 == 0) {
			last = up(ar, last, i);
		}
		else {
			last = down(ar, last, i);
		}
	}
}
int main() {
	unsigned long long n;
	cin >> n;
	vector<unsigned long long> v;
	unsigned long long maxx = read(n, &v);
	unsigned long long** ar = new unsigned long long* [maxx];
	fill(maxx, ar);
	for (long unsigned int i = 0; i < v.size(); i += 2) {
		cout << ar[v[i] - 1][v[i + 1] - 1] << "\n";
	}
	delete[]ar;
	return 0;
}
