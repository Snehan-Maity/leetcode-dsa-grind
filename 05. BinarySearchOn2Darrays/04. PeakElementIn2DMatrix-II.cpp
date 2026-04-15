#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
	// T.C. = O(log2 n) * O(m)
	// S.C. = O(1)
	int findMaxValue(vector<vector<int>> &mat, int m, int n, int col){ 	// O(m)
		int maxValue = -1, index = -1;
		for(int i=0; i<m; i++){
			if(mat[i][col] > maxValue){
				maxValue = mat[i][col];
				index = i;
			}
		}
		return index;
	}

public:
	vector<int> findPeak(vector<vector<int>> &mat, int m, int n){
		int low=0, high=n-1;
		while(low <= high){ 	// O(log2 n)
			int mid = low + (high-low)/2;
			int maxRowIndex = findMaxValue(mat, m , n, mid);  	// O(m)
			int left = (mid-1 >= 0)? mat[maxRowIndex][mid-1] : -1;
			int right = (mid+1 <= m)? mat[maxRowIndex][mid+1] : -1;
			if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) 	return {maxRowIndex, mid};
			else if(mat[maxRowIndex][mid] < left) 	high = mid-1;
			else 	low = mid+1;
		}
		return {-1, -1};
	}
};
int main(){
	int m, n;

	cout << "Enter the no of rows & columns : ";
	cin >> m >> n;

	vector<vector<int>> mat(m, vector<int>(n));
	cout << "Enter the matrix elements : \n";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}

	Solution obj;
	vector<int> ans = obj.findPeak(mat,m,n);
	if(ans[0] == -1) 	cout << "Peak does not exist in the Matrix" << endl;
	else 	cout << "One of the peak element is : " << mat[ans[0]][ans[1]] << endl;
	return 0;
}
