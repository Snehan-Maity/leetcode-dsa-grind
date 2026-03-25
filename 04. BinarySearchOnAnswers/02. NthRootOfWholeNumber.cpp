#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log n)
	// S.C. = O(1)
	long long power(int base, int exp){ 
		if(exp == 0)	return 1;
		if(base == 1)	return 1;
		long long res=1;
		for(int i=0; i<exp; i++){
			res*=base;
		}
		return res;
	}
    int findNthRoot(int no, int sq){ 	// O(n log n)
    	int low=1, high=no, ans;
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		long long val=power(mid,sq);	// O(n)
    		if(val == no)	return mid;
			else if(val < no)	low=mid+1;
			else 	high=mid-1;
		}
		return -1;
	}
};
int main(){
	int no,n;
	cout << "Enter the number to find the Nth root : ";
	cin >> no;
	cout << "Enter the Nth root value : ";
	cin >> n;
	Solution obj;
	int res=obj.findNthRoot(no,n);
	if(res != -1) 	cout << "The " << n << "th root of " << no << " is : " << res;
	else	cout << n << "th root of " << no << " is not possible";
	return 0;
}
