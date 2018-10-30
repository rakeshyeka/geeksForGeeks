//https://www.geeksforgeeks.org/ugly-numbers/
#include<iostream>
#include<vector>

using namespace std;

int nthUglyNumber(int n) {
	vector<int> uglyNum;
	uglyNum.push_back(1);
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	while(uglyNum.size() < n) {
		int minNum = uglyNum[i2]*2;
		if (uglyNum[i3]*3 < minNum) {
			minNum = uglyNum[i3]*3;
		}
		if (uglyNum[i5]*5 < minNum) {
			minNum = uglyNum[i5]*5;
		}

		uglyNum.push_back(minNum);

		if (minNum == uglyNum[i2]*2) {
			i2++;
		}
		if (minNum == uglyNum[i3]*3) {
			i3++;
		}
		if (minNum == uglyNum[i5]*5) {
			i5++;
		}
	}
	
	return uglyNum[uglyNum.size()-1];
}

int main() {
	int n;
	cin >> n;
	cout << nthUglyNumber(n) << endl;
}
