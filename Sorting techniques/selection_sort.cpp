#include <stdio.h>
void swap(int arr[], int n1,int n2){
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2]=temp;
}
void selection_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min = j;
			}
		}
		swap(arr,i,min);
	}
}
int main(){
	int n = 7;
	int arr[n]={5,1,4,2,7,0,12};
	selection_sort(arr,n);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	
}
