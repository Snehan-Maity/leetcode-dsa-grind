#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log n)
	// S.C. = O(1)
	int findMax(vector<int> &v){
		int maxi=INT_MIN;
		int n=v.size();
		for(int i=0; i<n; i++)	maxi=max(maxi, v[i]);
		return maxi;
	}	
	long long calTotalHrs(vector<int> &v, int hourly){
		int n=v.size();
		long long total=0;
		for(int i=0; i<n; i++){
			total += ceil((double) v[i] / (double)hourly);
		}
		return total;
	}
	int Koko(vector<int> &v, int h){
		int low=1, high=findMax(v);
		while(low <= high){
			int mid = low + (high-low)/2;
			if(calTotalHrs(v, mid) <= h)	high=mid-1;
			else	low = mid + 1;
		}
		return low;
	}
};
int main(){
    int n;
    cout << "Enter the number of piles : ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the bananas in each pile : ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int h;
    cout << "Enter total hours : ";
    cin >> h;

    Solution obj;
    int ans = obj.Koko(v, h);

    cout << "Minimum eating speed : " << ans << endl;

    return 0;
}
