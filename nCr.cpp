// https://www.geeksforgeeks.org/binomial-coefficient-dp-9
#include<iostream>

using namespace std;

int nCr(int n, int r) {
	int base = r > n-r ? r : n-r;
	long num=1, den=1;
	int i=base+1, j=1;
	while (i<=n || j<=n-base) {
		// n!/(base!)
		if (i<=n) {
			num *= i;
			i++;
		}
		// n-base !
		if (j<=n-base) {
			den *= j;
			j++;
		}
	}

	return num/den;
}

int nCrDynamic(int n, int r) {
	int ncr[n+1][r+1];
	// ncr = n-1Cr-1 + n-1Cr
	ncr[0][0] = 1;
	for (int i=1; i<=n; i++) {
		ncr[i][0] = 1;
		ncr[i][i] = 1;
		for (int j=1; j<i; j++) {
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
		}
	}
	return ncr[n][r];
}

int main() {
	int n, r;
	cin >> n >> r;
	cout << nCrDynamic(n,r) << endl;
}
