#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int uniqueNo(vector<int> nums, int n){
        int cal=0;
        for(auto it: nums)	cal=cal^it;
        return cal;
    }
};
int main(){
	int n;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	vector<int> arr(n);
	cout << "Enter the Array elements(All numbers twice, except one number) : ";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	Solution obj;
	int ans;
	cout << "Array : ";
	obj.displayArray(arr);
	ans=obj.uniqueNo(arr,n);
	cout << "\nThe number appearing once is : " << ans;
	return 0;
}
