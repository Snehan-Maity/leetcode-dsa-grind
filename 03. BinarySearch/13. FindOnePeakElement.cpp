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
    int peakElementInSortedArray(vector<int> nums, int n){
    	if(n==1)	return 0;	// If only one element is present in the Array
    	if(nums[0] > nums[1])	return 0; 	// If the first element is peak
    	if(nums[n-1] > nums[n-2])	return n-1;	// If the last element is peak
    	int low=1, high=n-2;	// From 2nd to 2nd last element as rest element have been already checked above
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 	return mid;
    		// We are in the left half (Increasing graph)
			if(nums[mid] > nums[mid-1])	low=mid+1;
			else if(nums[mid] > nums[mid+1]) 	high=mid-1; 	// We are in the right half
			else{
				// low=mid+1; 	// Any One either low or high 
				high=mid-1;
			}
		}
		return -1;  // If no such element is there
	}
};
int main(){
	int n,x,target;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements : \n";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
	Solution obj;
	cout << "\nOriginal Array : ";
	obj.displayArray(nums);
	int res=obj.peakElementInSortedArray(nums,n);
	if(res != -1) 	cout << "The Peak Element in the Array is " << nums[res] << " and it is present at index : " << res;
	else 	cout << "There is no Peak ELement in the Array";
	return 0;
}
