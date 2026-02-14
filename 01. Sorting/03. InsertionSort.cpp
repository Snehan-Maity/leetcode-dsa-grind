#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> arr){
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
}
void insertionSort(vector<int> &arr, int n){
	for(int i=1;i<n;i++){
		int j=i;
		while(j>0 && arr[j-1]>arr[j]){
			swap(arr[j-1],arr[j]);
			j--;
		}	
	}
}
int main(){
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Original Array : ";
	displayArray(arr);
	insertionSort(arr,n);
	cout<<"After Sorting : ";
	displayArray(arr);
	return 0;
}
