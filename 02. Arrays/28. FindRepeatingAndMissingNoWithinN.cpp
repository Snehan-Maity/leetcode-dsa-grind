#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
	}
    vector<int> repeatingAndMissingNo(vector<int> &nums, int n){
        long long Sn=n*(n+1)/2;		// S-Sn = x-y
        long long S2n=(n*(n+1)*(2*n+1))/6; 	// S2-S2n
        long long S=0, S2=0;
        for(int i=0; i<n; i++){
        	S+=nums[i];
        	S2+=(long long)nums[i] * (long long)nums[i];
		}
		long long val1=S-Sn; 	// x-y
		long long val2=S2-S2n;	//  x^2 - y^2 = (x+y)(x-y)
		val2=val2/val1;
		long long x=(val1 + val2)/2;	// As 2x = val + val2
		long long y=x-val1;
		return vector<int>{(int)x,(int)y};
	}
};
int main(){
	int n,x;
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
	vector<int> ans=obj.repeatingAndMissingNo(nums,n);
	cout << "\nRepeating Number : "<< ans.at(0);
	cout << "\nMissing Number : "<< ans.at(1);
	return 0;
}
