//https://www.geeksforgeeks.org/permutation-coefficient/
#include<iostream>

using namespace std;

int nPr(int n, int r) {
	int i=n-r;
	int npr = 1;
	for (int i=n-r+1; i<=n; i++) {
		npr*=i;
	}
	return npr;
}

int nPrDynamic(const int n, const int r) {
	int npr[n+1][r+1];
	npr[0][0] = 1;
	for (int i=0; i<=n; i++) {
		npr[i][0] = 1;
		for (int j=1; j<=min(i, r); j++) {
			npr[i][j] = npr[i-1][j] + j*npr[i-1][j-1];
		}
		if (i < r) {
			npr[i][i+1] = 0;
		}
	}
	return npr[n][r];
}

int main() {
	int n, r;
	cin >> n >> r;
	cout << nPrDynamic(n,r) << endl;
}
