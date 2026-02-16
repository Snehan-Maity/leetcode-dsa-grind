#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	void displayArray(vector<int> &arr, int no){
		for(int i=0;i<no;i++){
			cout << arr[i] << " ";
		}	
	}
	vector<int> leftRotate(vector<int> &arr, int n, int d){
		if(d>n)	return arr;  // If rotating index is >n ---> No change
		reverse(arr.begin(),arr.begin()+d);
		reverse(arr.begin()+d,arr.end());
		reverse(arr.begin(),arr.end());
		return arr;
	}
};

int main(){
	int n,d;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	vector<int> arr(n);
	cout << "Enter the Array elements : ";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << "Enter the index from where you want to rotate : ";
	cin >> d;
	
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(arr,n);
	arr=obj.leftRotate(arr,n,d);
	cout << "\nAfter Rotating the Array : ";
	obj.displayArray(arr,n);
}
