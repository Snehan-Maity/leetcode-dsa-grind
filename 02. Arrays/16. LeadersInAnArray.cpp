#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    vector<int> findLeaders(vector<int> &nums, int n){
        int maxi=INT_MIN;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
        	if(nums[i]>maxi){
        		ans.push_back(nums[i]);
        		maxi=nums[i];
			}
		}
		return ans;
	}
};
int main(){
	int n,x;
	cout << "Enter the number of Array elements : ";
	cin>>n;
    vector<int> arr ;
    cout << "Enter elements : ";
    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }

	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(arr);
	vector<int> leaders=obj.findLeaders(arr,n);
	cout << "\nLeaders in the array : ";
	obj.displayArray(leaders);
	return 0;
}
