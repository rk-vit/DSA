void count_sort(int arr[],int n){
	int max = findMax(arr);
	int cnt_arr[max+1];
	for(int i=0;i<max+1;i++) cnt_arr[i]=0;
	for(int i=0;i<n;i++) cnt_arr[arr[i]]++;
	for(int i=1;i<max+1;i++)cnt_arr[i]+=cnt_arr[i-1];
	int op_arr[n];
	for(int i=0;i<n;i++){
		op_arr[cnt_arr[arr[i]]-1]=arr[i];
		cnt_arr[arr[i]]--;
	}
 }
 
