#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    int longestConsecutiveSequence(vector<int> &nums, int n){
        int maxi=INT_MIN;
        unordered_set<int> st;
        for(auto it:nums){
        	st.insert(it);
		}
		for(auto it:st){
			if(st.find(it-1) == st.end()){
				int count=1;
				int x=it;
				while(st.find(x+1) != st.end()){
					count++;
					x++;
				}
				maxi=max(maxi,count);
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
	int maxLen=obj.longestConsecutiveSequence(arr,n);
	cout << "\nLongest Consecutive Sequence is of length : " << maxLen;
	return 0;
}
