#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int majorityElement(vector<int> &nums, int n){
        int el=0, cnt=1;
        for(int i=0;i<n;i++){
        	if(cnt==0){
        		el=nums[i];
        		cnt=1;
			}
        	else if(nums[i]==el)	cnt++;
        	else cnt--;
        	
		}
		int cnt2=0;
		for(auto it:nums)
			if(it==el)	cnt2++;
		if(cnt2>n/2)	return el;
		else return -1;
	}
};
int main(){
	int n,x;
	cout << "Enter the number of Array elements : ";
	cin>>n;
    vector<int> arr ;
    cout << "Enter elements : ";
    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }

	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(arr);
	int ans=obj.majorityElement(arr,n);
	if(ans!=-1)	cout<<"\nMajority element in the Array is : "<< ans;
	else	cout<<"\nNo Majority element found";
	return 0;
}
