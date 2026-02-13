#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> arr){
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
}
void bubbleSort(vector<int> &arr, int n){
	for(int i =0;i<n-1;i++){
		bool didSwap=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				didSwap=true;	
			}
		}
		if(didSwap==false)	break;	
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
	bubbleSort(arr,n);
	cout<<"After Sorting : ";
	displayArray(arr);
	return 0;
}
