// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
#include<iostream>

using namespace std;

int nthFibonacci(int n) {
	int i = 0;
	int n1 = 1, n2 = 0;
	int nFib;
	if (n==1) {
		return n2;
	} else if (n == 2) {
		return n1;
	}
	i = 2;
	while (i < n) {
		nFib = n1 + n2;
		n2 = n1;
		n1 = nFib;
		i++;
	}
	return nFib;
}

int main() {
	int n;
	cin >> n;
	cout << nthFibonacci(n) << endl;
}
