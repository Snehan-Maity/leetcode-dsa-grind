#include<bits/stdc++.h>
using namespace std;
class Solution {
	// T.C. = O(log2 (10^9) * m * log2 n)
	// S.C. = O(1)
private:
	int blackBox(vector<vector<int>> &mat, int m, int x){ 	// O(m * log2 n)
		int cnt=0;
		for(int i=0; i<m; i++){ 	
			cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin(); 	// O(log2 n)
		}
		return cnt;
	}

public:
	int findMedian(vector<vector<int>> &mat, int m, int n){
		int low=INT_MAX, high=INT_MIN;
		for(int i = 0; i < m; i++){
            low = min(low, mat[i][0]);         // Minimum among first elements
            high = max(high, mat[i][n-1]);     // Maximum among last elements
        }
		int req = (m * n) / 2;
		while(low <= high){
			int mid = low + (high-low)/2;
			int smallerEquals = blackBox(mat, m, mid);
			if(smallerEquals <= req) 	low = mid+1;
			else high = mid-1;
		}
		return low;
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
	cout << "The Median is : " << obj.findMedian(mat,m,n) << endl;
	return 0;
}
