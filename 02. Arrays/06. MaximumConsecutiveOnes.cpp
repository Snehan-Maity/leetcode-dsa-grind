#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int countOnes(vector<int> nums, int n){
        int count=0, maxOnes=INT_MIN;
        for(int i=0;i<n;i++){
        	if(nums[i]==1){
        		count++;
        		maxOnes=max(count, maxOnes);
			}
			else	count=0;
		}
        return maxOnes;
    }
};
int main(){
	int n;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	vector<int> arr(n);
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	Solution obj;
	int ans;
	cout << "Array : ";
	obj.displayArray(arr);
	ans=obj.countOnes(arr,n);
	cout << "\nMaximum Consecutive Ones : " << ans;
	return 0;
}
