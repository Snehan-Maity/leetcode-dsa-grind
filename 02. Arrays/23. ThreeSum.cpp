#include<bits/stdc++.h>
using namespace std;
// T.C. = O(n^2 + nlogn) = O(n^2)
// S.C. = O(1)
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout<<it<<" ";
		}
		return;
	}
	void displayAnswer(vector<vector<int>> &ans){
		int n=ans.size();
		cout << "\nThe unique triplets whose sum is 0 are : \n";
		for(int i=0; i<n; i++){
			cout<<"{";
			for(int j=0;j<3;j++){
				cout << ans[i][j] <<" ";
			}
			cout << "}" << "\n";
		}
		return;
	}
	vector<vector<int>> threeSum(vector<int> &arr, int n){
		vector<vector<int>> ans;
		sort(arr.begin(),arr.end());
		for(int i=0; i<n-2; i++){
			if(i>0 && arr[i]==arr[i-1])	continue;   // Avoiding duplicate in 1st element
			int j=i+1;
			int k=n-1;
			while(j<k){
				int sum=arr[i]+arr[j]+arr[k];
				if(sum<0)	j++;
				else if(sum>0)	k--;
				else{
					vector<int> temp={arr[i], arr[j], arr[k]};
					ans.push_back(temp);
					j++;
					k--;
					while(j<k && arr[j]==arr[j-1])	j++;	// Avoiding duplicate in 2nd element
					while(j<k && arr[k]==arr[k+1])	k--;	// Avoiding duplicate in 3rd element
				}
			}
		}
		return ans;
	}
		
};
int main(){
	int x,n;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	if(n < 3){
    	cout << "Not enough elements";
    	return 0;
	}
	vector<int> arr;
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++){
		cin >> x;
		arr.emplace_back(x);
	}
	
	Solution obj;
	vector<vector<int>> ans;
	cout << "Original Array : ";
	obj.displayArray(arr);
	ans=obj.threeSum(arr,n);
	if(!ans.empty())	obj.displayAnswer(ans);
	else	cout << "\nNo Triplets found whose sum is 0";
	return 0;
}
