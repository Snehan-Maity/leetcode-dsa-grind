#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int longestSubArray(vector<int> nums, int k){
    	int n=nums.size();
        int maxLen=-1,left=0,right=0;
        long long sum=nums[0];
        while(right<n){
        	while(left<=right && sum>k){
        		sum-=nums[left];
        		left++;
			}
			if(sum==k)	maxLen=max(maxLen, (right-left+1));
			right++;
			if(right<n)	sum+=nums[right];
		}
    return maxLen;
	}
};
int main(){
	int n,k;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	vector<int> arr(n);
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << "Enter the value of k : ";
	cin >> k;
	
	Solution obj;
	int ans;
	cout << "Array : ";
	obj.displayArray(arr);
	ans=obj.longestSubArray(arr,k);
	cout << "\nLongest SubArray with sum " << k << " is : "<< ans;
	return 0;
}
