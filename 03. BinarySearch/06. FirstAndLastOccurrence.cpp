#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
		cout << "\n";
		return;
	}
    pair<int, int> firstAndLastOccurrence(vector<int> nums, int n, int x) {
        vector<int> ans;
        int lb=lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        int ub=upper_bound(nums.begin(), nums.end(), x) - nums.begin() -1; 
        if(lb == n || nums[lb]!=x)	return {-1, -1};
        else return {lb, ub}; // As upper bound returns the next value index, so tp get the previous element we do -1
    }
};
int main(){
	int n,x,target;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements (In Sorted Order) : \n";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
	cout << "Enter the value you want to search : ";
	cin >> target; 
    
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(nums);
	pair<int, int> res=obj.firstAndLastOccurrence(nums,n,target);
	if(res.first == -1)	cout<< target << " is not present in the Array";
	else	cout << "First Occurrence is at index : "<< res.first <<" \nLast Occurrence is at index : "<< res.second;
	return 0;
}
