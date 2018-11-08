//https://www.geeksforgeeks.org/gold-mine-problem/
#include<iostream>

using namespace std;

const int MAX = 100;

int getMaxGold(int mine[][MAX], int size) {
	int right_1, right, right1;
	int maxGold = 0;
	for(int j=size-2; j>=0; j--) {
		for (int i=0; i<size; i++) {
			if (i > 0) {
				right_1 = mine[i-1][j+1];
			} else {
				right_1=0;
			}
			right = mine[i][j+1];
			if (i < size) {
				right1 = mine[i+1][j+1];
			} else {
				right1 = 0;
			}
		mine[i][j] += max(max(right_1, right), right1);
		maxGold = max(maxGold, mine[i][j]);
		}
	}
	return maxGold;
}

int main() {
	int size = 4;
	int mine[MAX][MAX] = {{10, 33, 13, 15},
		{22, 24, 04, 1},
		{5, 0, 2, 3},
		{0, 6, 14, 2}};
	cout << getMaxGold(mine, size) << endl;
}
