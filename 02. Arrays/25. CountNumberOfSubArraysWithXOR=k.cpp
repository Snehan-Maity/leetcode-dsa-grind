#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int countSubArrays(vector<int> &nums, int n, int k){
        int cnt=0, prefixXor=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(auto it:nums){
        	prefixXor ^= it;
        	int target=prefixXor^k;
        	if(mpp.find(target) != mpp.end())	cnt+=mpp[target];
        	mpp[prefixXor]+=1;
		}
		return cnt;
	}
};
int main(){
	int n,k,x;
	cout << "Enter the number of Array elements : ";
	cin>>n;
    vector<int> arr ;
    cout << "Enter elements : ";
    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }
	cout << "Enter the value of Sum : ";
	cin>>k;
	
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(arr);
	int count=obj.countSubArrays(arr,n,k);
	cout << "\nNumber of SubArrays with XOR as "<< k <<" is " << count;
	return 0;
}
