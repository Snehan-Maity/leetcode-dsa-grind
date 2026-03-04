#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<vector<int>> &arr){
		int n=arr.size();
		for(int i=0; i<n; i++){
			cout << "{ ";
    		for(int j=0;j<2;j++){
    			cout<< arr[i][j] << " ";
			}
			cout << "}\n";
    	}
	}
    vector<vector<int>> mergeOverlappingSubIntervals(vector<vector<int>> &arr, int n){
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
        	if(ans.empty() || arr[i][0]>ans.back()[1]){
        		ans.push_back(arr[i]);
			} 
			else{
				ans.back()[1]=max(ans.back()[1],arr[i][1]);
			}
		}
		return ans;
	}
};
int main(){
	int n,x;
	cout << "Enter the number of SubIntervals : ";
	cin>>n;
    vector<vector<int>> arr(n,vector<int>(2)) ;
    cout << "Enter elements : \n";
    for(int i=0; i<n; i++){
    	for(int j=0;j<2;j++){
    		cin >> x;
        	arr[i][j]=x;
		}
    }
	
	Solution obj;
	cout << "Original Array of Intervals :" << "\n";
	obj.displayArray(arr);
	vector<vector<int>> res=obj.mergeOverlappingSubIntervals(arr,n);
	cout << "\nAfter Merging, the Overlapping SubIntervals are :" << "\n";
	obj.displayArray(res);
	return 0;
}
