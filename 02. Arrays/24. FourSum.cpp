#include<bits/stdc++.h>
using namespace std;
// T.C. = O(n^3 + nlogn) = o(n^3)
// S.C. = o(1)
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout<<it<<" ";
		}
		return;
	}
	void displayAnswer(vector<vector<int>> &ans, int target){
		int n=ans.size();
		cout << "\nThe unique quadruples whose sum is " << target <<" are : \n";
		for(int i=0; i<n; i++){
			cout<<"{ ";
			for(int j=0;j<4;j++){
				cout << ans[i][j] <<" ";
			}
			cout << "}" << "\n";
		}
		return;
	}
	vector<vector<int>> fourSum(vector<int> &arr, int n, int target){
		vector<vector<int>> ans;
		sort(arr.begin(),arr.end());
		for(int i=0; i<n-3; i++){
			if(i>0 && arr[i]==arr[i-1])	continue;   // Avoiding duplicate in 1st element
			for(int j=i+1;j<n-2;j++){
				if(j>i+1 && arr[j]==arr[j-1])	continue;	// Avoiding duplicate in 2nd element
				int k=j+1;
				int l=n-1;
				while(k<l){
					long long sum = (long long)arr[i]+arr[j]+arr[k]+arr[l];
					if(sum<target) 		k++;
					else if(sum>target) 	l--;
					else{
						vector<int> temp={arr[i], arr[j], arr[k], arr[l]};
						ans.push_back(temp);
						k++;
						l--;
						while(k<l && arr[k]==arr[k-1])	k++;	// Avoiding duplicate in 3rd element
						while(k<l && arr[l]==arr[l+1])	l--;	// Avoiding duplicate in 4th element
					}
				}			
			}
		}
		return ans;
	}
			
};
int main(){
	int x,n,target;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	if(n < 4){
    	cout << "Not enough elements";
    	return 0;
	}
	vector<int> arr;
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++){
		cin >> x;
		arr.emplace_back(x);
	}
	cout << "Enter the value of Target : ";
	cin >> target;
	
	Solution obj;
	vector<vector<int>> ans;
	cout << "Original Array : ";
	obj.displayArray(arr);
	ans=obj.fourSum(arr,n,target);
	if(!ans.empty())	obj.displayAnswer(ans,target);
	else	cout << "\nNo quadruples found whose sum is "<< target;
	return 0;
}
