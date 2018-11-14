//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int> vec) {
	int n = vec.size();
	int left = 1, right = n, mid;
	while(left < right) {
		mid = (left+right)/2;
		if (left==mid) {
			if (vec.at(left) != left) {
				return left;
			} else if (right == n || vec.at(right) !=right) {
				return right;
			}
		}
		if (vec.at(mid) != mid) {
			// disturbance before mid
			right = mid;
		} else {
			// disturbance after mid
			left = mid;
		}
	}

	return 1;
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
