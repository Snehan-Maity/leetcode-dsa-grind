#include<bits/stdc++.h>
using namespace std;
class Solution{
    // T.C. = O(n)
    // S.C. = O(1)
public:
    void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
	}

    int maxProductSubArray(vector<int> &nums, int n){
        int prefix=1, suffix=1, ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(prefix == 0)     prefix=1;
            if(suffix == 0)     suffix=1;

            prefix = prefix*nums[i];
            suffix = suffix*nums[n-1-i];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};
int main(){
	int n, x;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements :";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
    
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(nums);
    cout << "\nThe Maximum Product SubArray is : " << obj.maxProductSubArray(nums,n) << endl;    
	return 0;
}