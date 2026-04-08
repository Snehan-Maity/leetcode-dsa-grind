#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(log2n)
	// S.C. = O(1)
    int findSquareRoot(int n){
    	if(n<0)	return -1;
    	int low=0, high=n, ans;
    	while(low<=high){
    		int mid=low+(high-low)/2;
    		if((mid * mid) <= n){
    			low=mid+1;
    			ans=mid;
    		}
			else	high=mid-1;
		}
		return high; //or ans
	}
};
int main(){
	int n;
	cout << "Enter the value to find the square root : ";
	cin >> n;
	Solution obj;
	int res=obj.findSquareRoot(n);
	if(res != -1) 	cout << "The Square Root of " << n << " is : " << res;
	else	cout << "Square root is not possible";
	return 0;
}
