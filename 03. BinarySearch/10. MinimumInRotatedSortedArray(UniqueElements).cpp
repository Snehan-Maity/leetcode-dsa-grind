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
    	int ans=INT_MAX;
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		if(nums[low]<=nums[mid]){	// Left Sorted
    			ans=min(ans,nums[low]);
    			low=mid+1;    			
			}
			else{	// Right Sorted
				ans=min(ans, nums[mid]);
				high=mid-1;
			}
		}
		return ans;
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
	cout << "The minimum number in the Array is : " << res;
	return 0;
}
