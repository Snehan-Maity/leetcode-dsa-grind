#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// T.C. = O(n log n + n * log(maxPos - minPos))
	// S.C. = O(1)
	int countStudents(vector<int> &arr, int pages){
		int students = 1;
		long long pagesStudent = 0;
		for(int i=0; i<arr.size(); i++){
			if(pagesStudent + arr[i] <= pages)		pagesStudent += arr[i];
			else{
				students += 1;
				pagesStudent = arr[i];
			}
		}
		return students;
	}
	int findPages(vector<int> &arr, int n, int m){
		if(m>n)		return -1;
		int low = *max_element(arr.begin(), arr.end());
		int high = accumulate(arr.begin(), arr.end(), 0);
		while(low <= high){
			int mid = low + (high-low)/2;
			int stud = countStudents(arr,mid);
			if(stud > m)	low = mid + 1;
			else 	high = mid - 1;
		}
		return low;
	}
};
int main(){
    int n, stud;
    cout << "Enter the total number of Books : ";
    cin >> n;

    vector<int> books(n);
    cout << "Enter the position of the Stalls : ";
    for(int i=0; i<n; i++){
        cin >> books[i];
    }
	
	cout << "Enter the number of Students : ";
	cin >> stud;
	
    Solution obj;
    int ans = obj.findPages(books, n, stud);

    cout << "The minimum, maximum no. of pages to be read by a Student is : " << ans << endl;
    return 0;
}
