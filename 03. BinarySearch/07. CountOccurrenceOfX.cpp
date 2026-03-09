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
    int countOccurrence(vector<int> nums, int n, int x){
    	pair<int, int> indexes= firstAndLastOccurrence(nums, n, x);
		if(indexes.first == -1)	return 0; 
		else return (indexes.second - indexes.first +1);
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
	cout << "Enter the value to find its occurrence : ";
	cin >> target; 
    
	Solution obj;
	cout << "\nOriginal Array : ";
	obj.displayArray(nums);
	int res=obj.countOccurrence(nums,n,target);
	if(res == 0)	cout << target << " is not present in the Array";
	else	cout << target << " occurs " << res << " times in the Array";
	return 0;
}
