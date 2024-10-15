#include <stdio.h>

void insertion_sort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main(){
	int n = 7;
	int arr[n]={5,1,4,2,7,0,12};
	insertion_sort(arr,n);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
