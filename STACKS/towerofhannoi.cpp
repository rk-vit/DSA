#include <stdio.h>

void toh(int n,char A,char C,char B){
	if(n==1){
		printf("Move disk 1 from rod %c to rod %c\n",A,C);
		return;
	}
	toh(n-1,A,B,C);
	printf("Move disk %d from rod %c to rod %c\n",n,A,C);
	toh(n-1,B,C,A);
}

int main(){
	int n = 10;
	toh(n,'A','C','B');
}
