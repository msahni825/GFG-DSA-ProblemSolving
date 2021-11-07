/*Count of number of given string in 2D character array*/
#include<bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))

int internalSearch(string input, int row, int col, string hay[], int row_max, int col_max, int xx){
	int found=0;
	if(row>=0 && row<=row_max && col>=0 && col<=col_max && input[xx]==hay[row][col]){
		char match=input[xx];
		xx+=1;
		hay[row][col]=0;
		if(input[xx]==0){
			found=1;
		}
		else{
			found+=internalSearch(input,row,col+1,hay,row_max,col_max,xx);	
			found+=internalSearch(input,row,col-1,hay,row_max,col_max,xx);
			found+=internalSearch(input,row+1,col,hay,row_max,col_max,xx);
			found+=internalSearch(input,row-1,col,hay,row_max,col_max,xx);
		}
		hay[row][col]=match;
	}
	return found;
}

// Function to search the string in 2d array
int searchStr(string input, int row, int col, string str[], int row_count, int col_count){
	int found=0;
	int r, c;
	for(r=0;r<row_count;++r){
		for(c=0;c<col_count;++c){
			found+=internalSearch(input, r, c, str, row_count-1, col_count-1, 0);
		}
	}
	return found;
}

int main(){
	string input;
	input="MAGIC";
	string arr[]={"BBABBM", "CBMBBA", "IBABBG", "GOZBBI", "ABBBBC", "MCIGAM"};
	string str[ARRAY_SIZE(arr)];
	int i;
	for(int i=0;i<ARRAY_SIZE(arr);++i){
		str[i]=arr[i];
	}
	cout<<"count: "<<" "<<searchStr(input,0,0,str,ARRAY_SIZE(arr),str[0].size())<<"\n";
	return 0;
}
