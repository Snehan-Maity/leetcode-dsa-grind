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
    int binarySearch(vector<int> &nums, int low, int high, int target){
    	if(low>high)	return -1;
    	int n=nums.size();
		int mid=low+(high-low)/2;
		if(nums[mid]==target)	return mid;
		else if(nums[mid]<target)	binarySearch(nums, mid+1, high, target);
		else	binarySearch(nums, low, mid-1, target);
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
	int index=obj.binarySearch(nums,0,n-1,target);
	if(index==-1)	cout << target << " is not present in the Array";
	else	cout << target <<" is present at index : " << index;
	return 0;
}
