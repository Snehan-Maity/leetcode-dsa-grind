#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	void displayArray(vector<int> &arr){
		for(auto it: arr){
			cout<<it<<" ";
		}
	}
	vector<int> performUnion(vector<int> &arr1, vector<int> &arr2){
		int n1=arr1.size();
		int n2=arr2.size();
		vector<int> unionn;
		int i=0,j=0;
		while(i<n1 && j<n2){
			if(arr1[i]<=arr2[j]){
				if(unionn.size()==0 || unionn.back()!=arr1[i])	unionn.push_back(arr1[i]);
				i++;
			}
			else if(arr2[j]<=arr1[i]){
				if(unionn.size()==0 || unionn.back()!=arr2[j])	unionn.push_back(arr2[j]);
				j++;
			}
		}
		while(i<n1){
			if(unionn.size()==0 || unionn.back()!=arr1[i])	unionn.push_back(arr1[i]);
				i++;
		}
		while(j<n2){
			if(unionn.size()==0 || unionn.back()!=arr2[j])	unionn.push_back(arr2[j]);
				j++;
		}
		return unionn;
	}
	
};

int main(){
	int n1,n2;
	cout<<"Enter the number of 1st Array elements : ";
	cin >> n1;
	vector<int> arr1(n1);
	cout << "Enter the 1st Array elements : ";
	for(int i=0; i<n1; i++){
		cin >> arr1[i];	
	}
	
	cout<<"Enter the number of 1st Array elements : ";
	cin >> n2;
	vector<int> arr2(n2);
	cout << "Enter the 2nd Array elements : ";
	for(int i=0; i<n2; i++){
		cin >> arr2[i];	
	}
	
	Solution obj;
	cout << "1st Array : ";
	obj.displayArray(arr1);
	cout << "2nd Array : ";
	obj.displayArray(arr2);
	vector<int> ans=obj.performUnion(arr1,arr2);
	cout << "\nUnion of 2 Arrays : ";
	obj.displayArray(ans);
}
