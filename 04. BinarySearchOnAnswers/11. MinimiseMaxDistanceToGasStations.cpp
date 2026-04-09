#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log n +n)
	// S.C. = O(1)
	int noOfGasStations(vector<int> &arr, long double dist){
		int cnt=0, n=arr.size();
		for(int i=1; i<=n; i++){
			int noInBetween = ((arr[i]-arr[i-1]) / dist);
			if(arr[i] - arr[i+1] / dist == noInBetween * dist)  	noInBetween--;
			cnt += noInBetween;
		}
		return cnt;
	}
	long double minimiseMaxDistance(vector<int> &arr, int n, int k){
		long double low=0, high=0;
		for(int i=0; i<n; i++){ 	// O(n)
			high = max(high, (long double) (arr[i+1] - arr[i]));
		}
		long double diff = 1e-6; 	// 10^(-6)
		while(high-low > diff){ 		// O(log n)
			long double mid = low + (high-low)/2.0;
			int cnt = noOfGasStations(arr,mid); 	// O(n)
			if(cnt > k)	low = mid;
			else 	high = mid;
		}
		return high;
	}
};
int main(){
	// Similar to the previous one
    int n, k;
    cout << "Enter the total number of gas stations : ";
    cin >> n;

    vector<int> stations(n);
    cout << "Enter the position of the stations (In Sorted Order): ";
    for(int i=0; i<n; i++){
        cin >> stations[i];
    }
	
	cout << "Enter the number of new stations to be placed : ";
	cin >> k;
	
    Solution obj;
    long double ans = obj.minimiseMaxDistance(stations, n, k);

    cout << "To minimise the maximum distance between 2 stations, : " << ans << endl;
    return 0;
}
