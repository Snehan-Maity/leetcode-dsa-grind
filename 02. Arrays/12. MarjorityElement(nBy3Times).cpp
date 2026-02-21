#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    vector<int> majorityElement(vector<int> &nums, int n){
        int el1=INT_MIN, cnt1=0;
        int el2=INT_MIN, cnt2=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
        	if(cnt1==0 && nums[i]!=el2){
        		el1=nums[i];
        		cnt1=1;
			}
			else if(cnt2==0 && nums[i]!=el1){
				el2=nums[i];
				cnt2=1;
			}
        	else if(nums[i]==el1)	cnt1++;
        	else if(nums[i]==el2)	cnt2++;
        	else{
        		cnt1--;
        		cnt2--;
			}
        	
		}
		int ch1=0,ch2=0;
		for(auto it:nums){
			if(it==el1)	ch1++;
			else if(it==el2)	ch2++;
		}
		if(ch1>n/3)	ans.push_back(el1);
		if(ch2>n/3)	ans.push_back(el2);
		return ans;
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
	vector<int> ans=obj.majorityElement(arr,n);
	
    if(ans.size()==0)
        cout<<"\nNo Majority element found";
    else{
        cout<<"\nMajority element(s) (> n/3 times) : ";
        obj.displayArray(ans);
    }
	return 0;
}
