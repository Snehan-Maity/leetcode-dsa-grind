#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(log(sum - max + 1) * O(n)
	// S.C. = O(1)
	int countPainters(vector<int> &arr, int units){
		int painters = 1;
		long long unitsPainted = 0;
		for(int i=0; i<arr.size(); i++){
			if(unitsPainted + arr[i] <= units)		unitsPainted += arr[i];
			else{
				painters += 1;
				unitsPainted = arr[i];
			}
		}
		return painters;
	}
	int findUnits(vector<int> &arr, int n, int k){
		if(k>n)		return -1; // Since every painter must paint one unit
		int low = *max_element(arr.begin(), arr.end());
		int high = accumulate(arr.begin(), arr.end(), 0);
		while(low <= high){
			int mid = low + (high-low)/2;
			int painters = countPainters(arr,mid);
			if(painters > k)	low = mid + 1;
			else 	high = mid - 1;
		}
		return low;
	}
};
int main(){
	// Similar to the previous one
    int n, k;
    cout << "Enter the total number of units to be painted : ";
    cin >> n;

    vector<int> paintings(n);
    cout << "Enter the time required to paint the Units : ";
    for(int i=0; i<n; i++){
        cin >> paintings[i];
    }
	
	cout << "Enter the number of Painters : ";
	cin >> k;
	
    Solution obj;
    int ans = obj.findUnits(paintings, n, k);

    cout << "The minimum time required to complete the whole array by combining all the painters : " << ans << endl;
    return 0;
}
