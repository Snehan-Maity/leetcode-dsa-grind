#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(m+n)
	// S.C. = O(1)
	pair<int, int> searchElement2(vector<vector<int>> &mat, int m, int n, int target){
		int row=0, col=n-1;
		while(row<m && col>=0){
			if(mat[row][col] == target) 	return {row,col};
			else if(mat[row][col] < target)		row++;
			else 	col--;
		}
		return {-1,-1};
	}
};
int main(){
	int m, n;

	cout << "Enter the no of rows & columns : ";
	cin >> m >> n;

	vector<vector<int>> mat(m, vector<int>(n));
	cout << "Enter the matrix elements (Sorted Row-wise & Column-wise) : \n";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}

	int x;
	cout << "Enter the element to be Searched : ";
	cin >> x;

	Solution obj;
	pair<int, int> ans = obj.searchElement2(mat,m,n,x);
	if(ans.first == -1) 	cout << x << " is not present in the Matrix" << endl;
	else 	cout << x <<" is present in the Matrix" << endl;
	return 0;
}
