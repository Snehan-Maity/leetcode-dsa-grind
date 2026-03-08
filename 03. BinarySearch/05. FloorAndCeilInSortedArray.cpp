#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
		cout << "\n";
		return;
	}
    vector<int> getFloorAndCeil(vector<int> nums, int n, int x) {
        vector<int> ans;
        int floor = -1;
        int ceil = -1;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==x){
                ceil = nums[mid];
                floor = nums[mid];
                break;
            }
            else if(nums[mid]>x){
                ceil = nums[mid];
                high = mid-1;
            }
            else{
                floor = nums[mid];
                low = mid+1;
            }
        }
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
   
    }
};
int main(){
	int n,x,target;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements (In Sorted Order) : \n";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
	cout << "Enter the value you want to search : ";
	cin >> target; 
    
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(nums);
	vector<int> res=obj.getFloorAndCeil(nums,n,target);
	cout << "Floor : "<< res[0] <<" \nCeil : "<< res[1];
	return 0;
}
