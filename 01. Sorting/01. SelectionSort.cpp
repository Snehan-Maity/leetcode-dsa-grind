#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> arr){
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
}
void selectionSort(vector<int> &arr, int n){
	for(int i =0;i<n-1;i++){
		int mini=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[mini])	mini=j;
		}
		swap(arr[i],arr[mini]);
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
	selectionSort(arr,n);
	cout<<"After Sorting : ";
	displayArray(arr);
	return 0;
}
