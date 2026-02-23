#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int maxSubArraySum(vector<int> &nums, int n){
        int maxi=-1,sum=0;
        for(int i=0;i<n;i++){
        	sum+=nums[i];
        	if(sum<0)	sum=0;
        	else{
        		maxi=max(maxi,sum);
			}
		}
		return maxi;
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
	int ans=obj.maxSubArraySum(arr,n);
	
    if(ans==-1)
        cout<<"\nNo Maximum SubArray found";
    else
        cout<<"\nMaximum SubArray Sum :  " << ans;
	return 0;
}
