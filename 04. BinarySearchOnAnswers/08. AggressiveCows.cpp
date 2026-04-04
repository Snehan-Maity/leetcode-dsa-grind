#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log n + n * log(maxPos - minPos))
	// S.C. = O(1)
	bool canWePlace(vector<int> &arr, int dist, int cows){
		int cntCows=1, last=arr[0];
		int n = arr.size();
		for(int i=1; i<n; i++){
			if(arr[i] - last >= dist){
				cntCows++;
				last=arr[i];
			}
		}
		if(cntCows >= cows)		return true;
		else 	return false;
	}
	int aggressiveCows(vector<int> &stalls, int k){
		sort(stalls.begin(), stalls.end()); 	// O(n log n)
		int n=stalls.size(), ans=-1;
		int low = 1, high = stalls[n-1] - stalls[0];
		while(low <= high){
			int mid = low + (high-low)/2;
			if(canWePlace(stalls, mid, k) == true){ 	// O(n)
				low = mid+1;
				ans = mid;
			}
			else	high = mid-1;
		}
		return high; 	// or return ans;
	}
};
int main(){
    int n, cows;
    cout << "Enter the number of Stalls : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the position of the Stalls : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
	
	cout << "Enter the number of Cows to be placed : ";
	cin >> cows;
	
    Solution obj;
    int ans = obj.aggressiveCows(arr, cows);

    cout << "The maximum, minimum distance after placing all the cows is : " << ans << endl;
    return 0;
}
