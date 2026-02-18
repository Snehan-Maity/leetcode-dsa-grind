#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr)	cout<<it<<" ";
	}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> intersection;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]<nums1[i])  j++;
            else{
                if(intersection.size()==0 || intersection.back()!=nums1[i])
                    intersection.push_back(nums1[i]);
                i++; j++;
            }
        }
        return intersection;
    }
};
int main(){
	int n1,n2;
	cout << "Enter the number of 1st Array elements : ";
	cin>>n1;
	vector<int> arr1(n1);
	cout << "Enter the 1st Array elements : ";
	for(int i=0;i<n1;i++)
		cin >> arr1[i];
	
	cout << "Enter the number of 2nd Array elements : ";
	cin>>n2;
	vector<int> arr2(n2);
	cout << "Enter the 2nd Array elements : ";
	for(int i=0;i<n2;i++)
		cin >> arr2[i];
	
	Solution obj;
	vector<int> ans;
	cout << "1st Array : ";
	obj.displayArray(arr1);
	cout << "\n2nd Array : ";
	obj.displayArray(arr2);
	ans=obj.intersection(arr1,arr2);
	cout << "\nIntersection of the 2 Arrays : ";
	obj.displayArray(ans);
	return 0;
}
