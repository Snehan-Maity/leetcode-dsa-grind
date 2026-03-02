#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayMatrix(vector<vector<int>> &mat, int m, int n){
		for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			cout << mat[i][j] << " ";
			}
			cout << endl;
    	}
	}
	void displayResult(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
	}
    vector<int> spiralMatrix(vector<vector<int>> &mat, int m, int n){
    	int top=0, bottom=m-1;
    	int left=0,right=n-1;
    	vector<int> ans;
    	while(top<=bottom && left<=right){
    		for(int i=left;i<=right;i++){
    			ans.push_back(mat[top][i]);
			}
			top++;
			for(int i=top;i<=bottom;i++){
    			ans.push_back(mat[i][right]);
			}
			right--;
			if(top<=bottom){
				for(int i=right;i>=left;i--){
    				ans.push_back(mat[bottom][i]);
				}
				bottom--;
			}
			if(left<=right){
				for(int i=bottom;i>=top;i--){
	    			ans.push_back(mat[i][left]);
				}
				left++;
			}
		}
		return ans;
	}
};
int main(){
	int m,n,x;
	cout << "Enter the number of rows and columns : ";
	cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the Matrix elements :\n";
    for(int i=0; i<m; i++){
    	for(int j=0; j<n; j++){
        	cin >> x;
    		mat[i][j]=x;
		}
    }
	
	Solution obj;
	cout << "\nOriginal Matrix : "<<"\n";
	obj.displayMatrix(mat,m,n);
	vector<int> res=obj.spiralMatrix(mat,m,n);
	cout << "\nSpiral Matrix Elements : "<<"\n";
	obj.displayResult(res);
	return 0;
}
