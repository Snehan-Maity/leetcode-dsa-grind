#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
	}
    void merge2SortedArrays(vector<int> &nums1, int n1, vector<int> &nums2, int n2){
        vector<int> ans;
        int left=n1-1;
        int right=0;
        while(left>=0 && right<n2){
        	if(nums1[left]>nums2[right]){
        		swap(nums1[left],nums2[right]);
        		left--; right++;
			}
			else	break;
		}
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
	}
};
int main(){
	int n1,n2,x;
    vector<int> nums1, nums2;
	cout << "Enter the number of elements in 1st Array: ";
	cin>>n1;
    cout << "Enter the 1st Array elements (In Sorted Order) : \n";
    for(int i=0; i<n1; i++){
    	cin >> x;
       	nums1.emplace_back(x);
    }
	cout << "Enter the number of elements in 2nd Array : ";
	cin>>n2;
    cout << "Enter the 2nd Array elements (In Sorted Order) : \n";
    for(int i=0; i<n2; i++){
    	cin >> x;
       	nums2.emplace_back(x);
    }
    
	Solution obj;
	cout << "First Array : ";
	obj.displayArray(nums1);
	cout << "Second Array : ";
	obj.displayArray(nums2);
	obj.merge2SortedArrays(nums1,n1,nums2,n2);
	cout << "\nAfter Merging,\nThe 1st Arrays is : ";
	obj.displayArray(nums1);
	cout << "\nThe 2nd Arrays is : ";
	obj.displayArray(nums2);
	return 0;
}

