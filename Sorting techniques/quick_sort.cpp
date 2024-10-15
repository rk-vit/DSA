#include <stdio.h>
void swap(int arr[], int n1,int n2){
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2]=temp;
}
int part_func(int arr[],int low,int high){
	int piviot = arr[low];
	int i=low;
	int j = high;
	while(i<j){
		while(arr[i]<=piviot&&i<high){
			i++;
		}
		while(arr[j]>piviot && j>low){
			j--;
		}
		if(i<j) swap(arr,i,j);
		
	}
	swap(arr,j,low);
	return j;
}
void quick_sort(int arr[],int low,int high){
	if(low<high){
		int part = part_func(arr,low,high);
		quick_sort(arr,low,part-1);
		
		quick_sort(arr,part+1,high);
	}
}
int main(){
	int n = 7;
	int arr[n]={5,1,4,2,7,0,12};
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
