#include <stdio.h>
int ls(int arr[],int n , int target){
	bool found = false ;
	for(int i=0;i<n;i++){
		if(arr[i]==target){
			found = true;
			return i;
				
		}
	}
	if(!found) return -1;
}
int main(){
	int n = 5;
	int arr[n] ={1,2,3,4,5};
	printf("%d",ls(arr,5,3));
}


