#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log(maxi-mini+1))
	// S.C. = O(1)
	int sumByD(vector<int> &arr, int div){
		int sum=0, n=arr.size();
		for(int i=0; i<n; i++){
			sum += ceil((double) arr[i] / (double) div);
		}
		return sum;
	}
	int smallestDiv(vector<int> &arr, int threshold){
		if(threshold < arr.size())	return -1;
		int low=1, high= *max_element(arr.begin(), arr.end());
		while(low <= high){
			int mid = low + (high-low)/2;
			if(sumByD(arr,mid) <= threshold)	high=mid-1;
			else 	low = mid+1;
		}
		return low;
	}
};
int main(){
    int n;
    cout << "Enter the number elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the values : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int th;
    cout << "Enter the threshold value : ";
    cin >> th;

    Solution obj;
    int ans = obj.smallestDiv(nums, th);

    cout << "The Smallest Divisor is : " << ans << endl;

    return 0;
}
