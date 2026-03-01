#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayMatrix(vector<vector<int>> &mat, int n){
		for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			cout << mat[i][j] << " ";
			}
			cout << endl;
    	}
	}
    void rotateMatrix(vector<vector<int>> &mat, int n){
    	// First Transpose
    	for(int i=0; i<n-1; i++){
    		for(int j=i+1; j<n; j++){
    			swap(mat[j][i],mat[i][j]);
			}
		}
		// Then Reverse Every Row
		for(int i=0; i<n; i++){
			reverse(mat[i].begin(),mat[i].end());
		}
	}
};
int main(){
	int n,k,x;
	cout << "Enter the size of Matrix : ";
	cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the Matrix elements :\n";
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
        	cin >> x;
    		mat[i][j]=x;
		}
    }
	
	Solution obj;
	cout << "Original Matrix : "<<"\n";
	obj.displayMatrix(mat,n);
	obj.rotateMatrix(mat,n);
	cout << "\nAfter Rotating by 90 degree : "<< "\n";
	obj.displayMatrix(mat,n);
	return 0;
}
