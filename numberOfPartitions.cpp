//https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/

#include<iostream>
#include<vector>

using namespace std;

int insertInto(vector<vector<int>> *partitions, int i, int j, int val) {
	if (i > (*partitions).size()) {
		(*partitions).resize(i+1);
	}
	if (j > (*partitions)[i].size()) {
		(*partitions)[i].resize(j+1);
	}
	(*partitions)[i][j] = val;
}

int kPartitions(vector<vector<int>> *partitions, int n, int k) {
	if (k==1 || n==k) {
		insertInto(partitions, n, k, 1);
		return 1;
	}
	if ((*partitions)[n][k] != 0) {
		return (*partitions)[n][k];
	}
	// adding nth element to n-1 with k partitions
	// i.e. adding nth element as new partition to k-1 partitions of n-1 elements
	int append = kPartitions(partitions, n-1, k-1);
	// or inserting nth element into every partition of k from n-1 elements
	int insert = k*kPartitions(partitions, n-1, k);
	insertInto(partitions, n, k, append+insert);

	return append + insert;
}

int totalPartitionCount(int n) {
	int partitionCount = 0;
	vector<vector<int>> partitions(n+1);
	for (int i=1; i<=n; i++) {
		partitionCount += kPartitions(&partitions, n, i);
	}

	return partitionCount;
}

int main() {
	int n;
	cin >> n;
	cout << totalPartitionCount(n) << endl;
}
