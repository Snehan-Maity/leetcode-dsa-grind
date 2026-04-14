#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(log2 (m*n))
	// S.C. = O(1)
	int searchElement(vector<vector<int>> &mat, int m, int n, int target){
		int low=0, high=(n*m - 1);
		while(low <= high){
			int mid = low + (high-low)/2;
			int row=mid/n, col=mid%n;
			if(mat[row][col] == target) 	return true;
			else if(mat[row][col] < target)		low = mid+1;
			else 	high = mid-1;
		}
		return false;
	}
};
int main(){
	int m, n;

	cout << "Enter the no of rows & columns : ";
	cin >> m >> n;

	vector<vector<int>> mat(m, vector<int>(n));
	cout << "Enter the matrix elements (In Sorted Order) : \n";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}

	int x;
	cout << "Enter the element to be Searched : ";
	cin >> x;

	Solution obj;
	if(obj.searchElement(mat,m,n,x)) 	cout << x <<" is present in the Matrix" << endl;
	else 	cout << x << " is not present in the Matrix" << endl;
	return 0;
}
