#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    void sorting(vector<int> &nums, int n){
        int left=0,mid=0,right=n-1;
        while(mid<=right){
        	if(nums[mid]==0){
        		swap(nums[left],nums[mid]);
        		left++;
        		mid++;
			}
			else if(nums[mid]==2){
				swap(nums[mid],nums[right]);
				right--;
			}
			else	mid++;
		}
    return;
	}
};
int main(){
	int n,x;
	cout << "Enter the number of Array elements : ";
	cin>>n;
	if(n <= 0){
        cout << "Invalid size!";
        return 0;
    }
    vector<int> arr;
    cout << "Enter elements (Conatining only 0, 1, 2) : ";

    for(int i=0; i<n; i++){
        cin >> x;
        if(x != 0 && x != 1 && x != 2){
            cout << "Invalid input! Only 0,1,2 allowed.\n";
            return 0;
        }
        arr.push_back(x);
    }

	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(arr);
	obj.sorting(arr,n);
	cout << "\nAfter Sorting : ";
	obj.displayArray(arr);
	return 0;
}
