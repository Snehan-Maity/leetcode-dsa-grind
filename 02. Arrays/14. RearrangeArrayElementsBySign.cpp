#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    vector<int> rearrangeBySign(vector<int> &nums, int n){
        vector<int> ans(n);
        int posIndex=0, negIndex=1;
        for(int i=0;i<n;i++){
        	if(nums[i]>0){
        		ans[posIndex]=nums[i];
        		posIndex+=2;
			}
			else{
				ans[negIndex]=nums[i];
				negIndex+=2;
			}
		}
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
	vector<int>res=obj.rearrangeBySign(arr,n);
	cout << "\nAfter Rearranging : ";
	obj.displayArray(res);
	return 0;
}
