#include <bits/stdc++.h>
using namespace std;
class Solution{
    // Return the count for arr[i] > arr[j]
    // T.C. : O(n log n)
    // S.C. : O(1)
private :
    // Modifications in Merge Sort code
    int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
        int left = low;
        int right = mid + 1;
        int cnt = 0;    // Variable to count inversions

        // Merge elements in sorted order and count inversions
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);    // All remaining left elements are inversions
                right++;
            }
        }

        // If left half still has elements
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If right half still has elements
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

    // Copy back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

// Merge sort function that counts inversions
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);    // Count inversions in left half
        cnt += mergeSort(arr, mid + 1, high);   // Count inversions in right half
        cnt += merge(arr, low, mid, high);      // Count inversions during merge
        return cnt;
    }

public :
    void displayArray(vector<int> &arr){
		for(auto it:arr){
			cout << it << " ";
		}
	}
    // Function to get number of inversions
    int numberOfInversions(vector<int>& a, int n) {
        return mergeSort(a, 0, n - 1);
    }
};
int main(){
	int n, x;
    vector<int> nums;
	cout << "Enter the number of elements : ";
	cin>>n;
    cout << "Enter the elements :";
    for(int i=0; i<n; i++){
    	cin >> x;
       	nums.emplace_back(x);
    }
    
	Solution obj;
	cout << "Original Array : ";
	obj.displayArray(nums);
	int cnt=obj.numberOfInversions(nums,n);
    cout << "\nThe number of inversions are: " << cnt << endl;    
	return 0;
}

