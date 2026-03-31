#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log(maxi-mini+1))
	// S.C. = O(1)
	bool possible(vector<int> &arr, int day, int m, int k){
		int cnt=0, noB=0;
		int n=arr.size();	
		for(int i=0; i<n; i++){
			if(arr[i] <= day)	cnt++;
			else{
				noB += (cnt/k);
				cnt=0;
			}
		}
		noB += (cnt/k);
		if(noB >= m)	return true;
		else	return false;
	}
	int makeBouquets(vector<int> &arr, int m, int k){
		if(arr.size() < 1LL*m*k)	return -1;
		
		int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        
		int low=mini, high=maxi, ans=high;
		while(low <= high){
			int mid = low + (high-low)/2;
			if(possible(arr,mid,m,k) == true){
				ans=mid;
				high=mid-1;
			}
			else	low=mid+1;
		}
		return ans;		// or return low;
	}
};n
int main(){
    int n;
    cout << "Enter the number of flower plants : ";
    cin >> n;

    vector<int> bloomDay(n);
    cout << "Enter the blooming day of each flowers : ";
    for(int i = 0; i < n; i++){
        cin >> bloomDay[i];
    }

    int m;
    cout << "Enter the total number of bouquets : ";
    cin >> m;

	int k;
    cout << "Enter the total number of adjacent flowers required : ";
    cin >> k;
    
    Solution obj;
    int ans = obj.makeBouquets(bloomDay, m, k);

    cout << "Minimum number of days to make M bouquets : " << ans << endl;

    return 0;
}
