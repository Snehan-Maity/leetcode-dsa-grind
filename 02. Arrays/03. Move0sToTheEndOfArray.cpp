#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	void displayArray(vector<int> &arr){
		for(auto it: arr){
			cout<<it<<" ";
		}
	}
	void moveZeros(vector<int> &arr, int n){
		if(n==0)	return;
		int i=-1;
		for(int j=0;j<n;j++){ //Finding the fist 0's index
			if(arr[j]==0){
				i=j;
				break;
			}
		}
		if(i==-1)	return;
		for(int j=i+1;j<n;j++){
			if(arr[j]!=0)	swap(arr[i++],arr[j]);
		}
		return;
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
	cout << "Original Array : ";
	obj.displayArray(arr);
	obj.moveZeros(arr,n);
	cout << "\nAfter moving the zeros : ";
	obj.displayArray(arr);
}
