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
	// T.C. = O(log2n)
	// S.C. = O(1)
    int searchInRotatedSortedArray(vector<int> nums, int n, int target){
    	int low=0, high=n-1;
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		if(nums[mid] == target)	return mid;
    		if(nums[low]==nums[mid] && nums[mid]==nums[high]){  // If array contains duplicate searched element
    			low+=1;
    			high-=1;
    			continue;
			}
    		// If target is not found, then find the Sorted Half
    		if(nums[low]<=nums[mid]){	// Left Sorted
    			if(nums[low]<=target && target<=nums[mid])	high=mid-1;
    			else 	low=mid+1;
			}
			else{	// Right Sorted
				if(nums[mid]<=target && target<=nums[high])		low=mid+1;
				else 	high=mid-1;
			}
		}
		return -1;	// If element is not present
	}
};
int main(){
	int n,x,target;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements (In Rotated Sorted Order) : \n";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
	cout << "Enter the value to search : ";
	cin >> target; 
    
	Solution obj;
	cout << "\nOriginal Array : ";
	obj.displayArray(nums);
	int res=obj.searchInRotatedSortedArray(nums,n,target);
	if(res == -1)	cout << target << " is not present in the Array";
	else	cout << target << " is present at index " << res << "  in the Array";
	return 0;
}
