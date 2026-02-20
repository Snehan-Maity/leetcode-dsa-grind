#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int twoSum(vector<int> &nums, int k){
    	int n=nums.size();
        int left=0,right=n-1;
        sort(nums.begin(),nums.end());
        while(left<right){
        	int sum=nums[left]+nums[right];
        	if(sum==k)	return nums[left];
        	else if(sum<k)	left++;
			else	right--;
		}
    return -1;
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
	ans=obj.twoSum(arr,k);
	if(ans!=-1)		cout << "\nThe elements in the Array whose sum = " << k << " is : "<< ans << " and "<< k-ans;
	else	cout<< "\nNo elements found whose sum is = "<<k;
	return 0;
}
