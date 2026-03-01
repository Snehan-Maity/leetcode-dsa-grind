#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayMatrix(vector<vector<int>> &mat, int n, int m){
		for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cout << mat[i][j] << " ";
			}
			cout << endl;
    	}
	}
    void setMatrixZeros(vector<vector<int>> &mat, int n, int m){
    	int col0=1;
    	int i,j;
        for(i=0; i<n; i++){
    		for(j=0; j<m; j++){
    			if(mat[i][j] == 0){
					mat[i][0]=0;  // Mark the i'th row
    				if(j!=0)	mat[0][j]=0;	// As the first box of column direction is to be stored in col0
    				else	col0=0;	 // Mark the j'th column
				}
    		}
    	}
    	for(i=1; i<n; i++){
    		for(j=1; j<m; j++){
    			if(mat[i][j] != 0){
    				if(mat[0][j] == 0 || mat[i][0] == 0)	mat[i][j]=0;	// Check for Column and Row
				}
			}
		}
		if(mat[0][0] == 0){
			for(j=0; j<m; j++)	mat[0][j]=0;
		}
		if(col0 == 0){
			for(i=0; i<n; i++)	mat[i][0]=0;
		}
	}
};
int main(){
	int n,m,k,x;
	cout << "Enter the number of rows and columns : ";
	cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the Matrix elements(Only 0s and 1s) :\n";
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
        	cin >> x;
    		mat[i][j]=x;
		}
    }
	
	Solution obj;
	cout << "Original Matrix : "<<"\n";
	obj.displayMatrix(mat,n,m);
	obj.setMatrixZeros(mat,n,m);
	cout << "\nAfter Arranging : "<< "\n";
	obj.displayMatrix(mat,n,m);
	return 0;
}
