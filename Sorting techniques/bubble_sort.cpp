#include <stdio.h>
void swap(int arr[], int n1,int n2){
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2]=temp;
}
void bubble_sort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	}
}


int main(){
	int n = 7;
	int arr[n]={5,1,4,2,7,0,12};
	bubble_sort(arr,n);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
