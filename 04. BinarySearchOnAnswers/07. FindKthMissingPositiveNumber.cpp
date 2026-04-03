#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(log n)
	// S.C. = O(1)
	int missingPositiveNumber(vector<int> &nums, int missPos){
		int low=0, high=nums.size()-1;
		while(low <= high){
			int mid = low + (high-low)/2;
			int missing = nums[mid] - (mid+1);
			if(missing < missPos)	low = mid + 1;
			else 	high = mid - 1;
		}
		return high + 1 + missPos; 		// or return low + k
	}
};
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (Positive, unique and in Sorted Order) : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int missPos;
    cout << "Enter the position of the Missing positive number to find : ";
    cin >> missPos;

    Solution obj;
    int ans = obj.missingPositiveNumber(nums, missPos);

    cout << "The " << missPos <<"th missing positive number is : "<< ans << endl;
    return 0;
}
