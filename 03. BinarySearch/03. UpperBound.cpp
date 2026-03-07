// Default UpperBound function : 
// ub=upper_bound(arr.begin(), arr.end(),x) - arr.begin();

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
    int upperBound(vector<int> &nums, int n, int target){
    	int low=0, high=n-1, ans=n;
    	while(low <= high){		// T.C. = O(log2n)
			int mid=low+(high-low)/2;
			if(nums[mid]>target){
				ans=mid;
				high=mid-1;
			}
			else	low=mid+1;
		}
		return ans;
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
	int ind=obj.upperBound(nums,n,target);
	cout << "Upper Bound of "<< target <<" is at index : "<<ind;
	return 0;
}
