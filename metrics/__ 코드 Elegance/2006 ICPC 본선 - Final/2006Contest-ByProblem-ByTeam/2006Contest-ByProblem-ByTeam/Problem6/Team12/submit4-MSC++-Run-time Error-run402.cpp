#include <stdio.h>

void main(){
	int num,  i, j, number, sum, temp, k;
	int low, high;
	float result;
	int value[40];
	scanf("%d", &num);

	for(i=0; i<num; i++){
		scanf("%d", &number);

		for(j=0; j<number; j++){
			scanf("%d %d",&value[j*2], &value[j*2+1]);
		}
		scanf("%d", &sum);

		low=0;
		for(j=0; j<number*2; j+=2){
			temp=1;
			for(k=0; k<number*2; k+=2){
				if(j!=k){
					temp*=value[k];
				}
			}
			low+=temp;
		}

		high=sum;

		for(j=0; j<number*2; j+=2){
			high*=value[j];
		}

		for(j=1; j<number*2; j+=2){
			temp=value[j];
			for(k=0; k<number*2; k+=2){
				if(k!=j-1){
					temp*=value[k];
				}
			}
			high+=temp;
		}
		for(j=0; j<high; j++){
			if(low*j==high){
				break;
			}
		}
		if(j!=high){
			printf("%d\n",high/low);
		}
		else{
			printf("0\n");
		}		
	}
}
