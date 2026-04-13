#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(m * log2 n)
	// S.C. = O(1)
	int maximumOnes(vector<vector<int>> &mat, int m, int n){
		int cntMax=0, index=-1;
		for(int i=0; i<m; i++){
			int cntOnes = n - (lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin());
			if(cntOnes > cntMax){
				cntMax = cntOnes;
				index = i;
			}
		}
		return index;
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
	cout << "The row with maximum no of 1s is : " << obj.maximumOnes(mat,m,n) << endl;
	return 0;
}
