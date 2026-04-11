#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(log(min(n1, n2)))
	// S.C. = O(1)
	double median(vector<int> &a, vector<int> &b){
		int n1=a.size(), n2=b.size();
		int n=n1+n2;
		if(n1 > n2) 	return median(b,a);
		int low=0, high=n1, left=(n1+n2+1)/2;
		while(low <= high){
			int mid1 = (low+high) >> 1; 	// Dividing by 2^1
			int mid2 = left-mid1; 	// No. of elements req on LHS after placing 1st element
			int l1 = INT_MIN, l2 = INT_MIN;
			int r1 = INT_MAX, r2 = INT_MAX;
			if(mid1 <n1) 	r1 = a[mid1];			
			if(mid2 <n2) 	r2 = b[mid2];
			if(mid1-1 >= 0) 	l1 = a[mid1-1];
			if(mid2-1 >= 0) 	l2 = b[mid2-1];
			if(l1 <= r2 && l2 <= r1){
				if(n%2 == 1) 	return max(l1, l2); 	// Odd
				else return ((double) (max(l1,l2) + (double)min(r1,r2)) / 2.0); 	// Even
			}
			else if(l1 > r2) 	high=mid1-1;
			else 	low=mid1+1;
		}	
		return 0.0;
	}
};
int main(){
	int n1, n2;
	cout << "Enter the no of elements in the 1st Array : ";
	cin >> n1;

	vector<int> a(n1);
	cout << "Enter the elements of the 1st Array (In Sorted Order) : ";
	for(int i = 0; i < n1; i++) cin >> a[i];

	cout << "Enter the no of elements in the 2nd Array : ";
	cin >> n2;

	vector<int> b(n2);
	cout << "Enter the elements of the 2nd Array (In Sorted Order) : ";
	for(int i = 0; i < n2; i++) cin >> b[i];

	Solution obj;
	cout << "Median of the two arrays combining is : " << obj.median(a, b);

	return 0;
}
