#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    void nextPermutation(vector<int> &nums, int n){
        int index=-1;
        for(int i=n-2;i>=0;i--){
        	if(nums[i+1]>nums[i]){
        		index=i;
        		break;
			}
		}
		if(index==-1){
			reverse(nums.begin(),nums.end());
			return;
		}
		for(int i=n-1;i>index;i--){
			if(nums[i]>nums[index]){
				swap(nums[i],nums[index]);
				break;
			}
		}
		reverse(nums.begin()+index+1,nums.end());
		return;
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
	obj.nextPermutation(arr,n);
	cout << "\nNext Permutation : ";
	obj.displayArray(arr);
	return 0;
}

