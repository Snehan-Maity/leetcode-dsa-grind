#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findElement(int n, int r){   // Performing (row-1)C(col-1)
		int res=1,num=n-1;
		for(int i=0; i<r-1; i++){
			res=res*(num-i);
			res=res/(i+1);
		}
		return res;
	}
	void printRow(int r){
		for(int i=1;i<=r;i++){
			cout << findElement(r,i) << " ";
		}
		return 0;
	}
    void printPascalsTriangle(int n){
    	cout<<"Pascal's Triangle :\n";
    	int spaces=n-1;
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<spaces;j++){
    			cout << " ";
			}
    		printRow(i);
    		cout<<"\n";
    		spaces-=1;
		}
		return 0;
	}
	
};
int main(){
	int ch,r,c,n,ans;
	
	Solution obj;
	while(1){
		cout << "\n0.Exit \n1.Find the element at (r,c) \n2.Print the entire row for(r) \n3.Print the whole Pascal's Triangle for(n)";
		cout << "\nEnter your choice : ";
		cin >> ch;
		switch(ch){
			case 0 :exit(0);
					break;
			case 1 :cout<<"Enter the row and column no : ";
					cin >> r >> c;
					ans=obj.findElement(r,c);
					cout << "Element at ("<<r<< "," <<c<<") is : "<<ans<<"\n";
					break;
			case 2 :cout<<"Enter the row you want to print : ";
					cin >> r;
					obj.printRow(r);
					break;
			case 3 :cout<<"Enter the size of Triangle(value of n) : ";
					cin >> n;
					obj.printPascalsTriangle(n);
					break;
			default : cout << "Invalid Input!";
		}
	}
	return 0;
}
