#include<bits/stdc++.h>
using namespace std;
void displayArray(vector<int> &arr, int no){
	for(int i=0;i<no;i++){
		cout << arr[i] << " ";
	}
}
int removeDuplicates(vector<int> &arr, int n){
	if(n==0)	return -1;
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[j]!=arr[i])	arr[++i]=arr[j];
	}
	return i+1;
}
int main(){
	int n;
	printf("Enter the number of Array elements : ");
	cin>>n;
	vector<int> arr(n);
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << "Original Array : ";
	displayArray(arr,n);
	int x=removeDuplicates(arr,n);
	cout << "\nNew Array : ";
	displayArray(arr,x);
}
