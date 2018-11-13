//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

#include<iostream>
#include<vector>

using namespace std;

// Any order
int missingNumber(vector<int> vec) {
	int n = vec.size();
	int i=1, sum=0;
	while(i<n) {
		sum+=vec.at(i);
		if (i%2 == 0) {
			sum-=n+1;
		}
		i++;
	}
	if (n%2==1) {
		sum-=(n+1)/2;
	} else {
		sum-=n+1;
	}
	return -1*sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i=1; i<n; i++) {
		cin >> vec[i];
	}
	cout << missingNumber(vec) << endl;
}

