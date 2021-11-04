/*Index of first one*/

#include<bits/stdc++.h>
using namespace std;

void indexOfFirstOne(int arr[], int l, int h){
	int mid=0;
	while(l<=h){
		mid=(l+h)/2;	
		if(arr[mid]==1 && (mid==0 || arr[mid-1]==0)){
			break;
		}
		//first 1 lies to the left of 'mid'
		else if(arr[mid]==1){
			h=mid-1;
		}
		//first 1 lies to the right of 'mid
		else{
			l=mid+1;
		}
	}
	cout<<mid<<"\n";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int low=0;
	int high=1;
	while(arr[high]==0){
		low=high;
		high=2*high;
	}
	indexOfFirstOne(arr,low,high);
	return 0;
}
