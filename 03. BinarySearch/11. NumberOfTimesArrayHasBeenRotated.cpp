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
    	int minInd=0;
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		if(nums[low]<=nums[mid]){	// Left Sorted
    			if(nums[low] < nums[minInd]) minInd = low;
    			low=mid+1;    			
			}
			else{	// Right Sorted
				if(nums[mid] < nums[minInd]) minInd = mid;
				high=mid-1;
			}
		}
		return minInd;
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
	Solution obj;
	cout << "\nOriginal Array : ";
	obj.displayArray(nums);
	int res=obj.searchInRotatedSortedArray(nums,n,target);
	cout << "The Array has been rotated " << res << " times";
	return 0;
}
