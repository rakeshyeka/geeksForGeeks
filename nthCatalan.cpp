//https://www.geeksforgeeks.org/program-nth-catalan-number/

#include<iostream>
#include<vector>

using namespace std;

int nthCatalanRec(vector<int> *catalan, int n) {
	int sum = 0;
	if (n==0 || (*catalan)[n] != 0) {
		return (*catalan)[n];
	}
	for (int i=0; i<n; i++) {
		sum += nthCatalanRec(catalan, i)
			* nthCatalanRec(catalan, n-1-i);
	}
	(*catalan)[n] = sum;

	return sum;
}

int nthCatalan(int n) {
	vector<int> catalan(n+1);
	catalan[0] = 1, catalan[1] = 1;
	return nthCatalanRec(&catalan, n);
}

int main() {
	int n;
	cin >> n;
	cout << nthCatalan(n) << endl;
}
