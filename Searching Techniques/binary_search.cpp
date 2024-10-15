#include <stdio.h>


int bs(int arr[],int low,int high,int target){
	if(low>=high) return -1;
	int mid = (low+high)/2;
	if(arr[mid]==target) return mid;
	if(arr[mid]<target) return bs(arr,mid+1,high,target);
	if(arr[mid]>target) return bs(arr,low,mid,target);
}
int main(){
	int n = 5;
	int arr[n] ={1,2,3,4,5};
	printf("%d",bs(arr,0,5,5));
}

