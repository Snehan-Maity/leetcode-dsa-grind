#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n * log(sum(weights) - max(weights) + 1))
	// S.C. = O(1)
	int numberOfDays(vector<int> &weights, int cap){
		int days=1, load=0;
		for(int i=0; i<weights.size(); i++){
			if(weights[i] +load > cap){
				days += 1;
				load = weights[i];
			}
			else	load += weights[i];
		}	
		return days;
	}
	int leastWeightCapacity(vector<int> &weights, int days){
		int low = *max_element(weights.begin(), weights.end());
		int high = accumulate(weights.begin(), weights.end(), 0);
		while(low <= high){
			int mid = low + (high-low)/2;
			int noD = numberOfDays(weights, mid);
			if(noD <= days)	high = mid - 1;
			else 	low = mid + 1;
		}
		return low;
	}
};
int main(){
    int n;
    cout << "Enter the number elements to carry : ";
    cin >> n;

    vector<int> weights(n);
    cout << "Enter their weights : ";
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    int days;
    cout << "Enter the no of Days within which we need to carry the weights : ";
    cin >> days;

    Solution obj;
    int ans = obj.leastWeightCapacity(weights, days);

    cout << "The Minimum Capacity of the Ship must be : " << ans << " in order to complete the transportation within " << days << " days";
    return 0;
}
