#include<stdio.h>

int matrix(int ar[100][100],int x,int y){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%d",&ar[i][j]);
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d",ar[i][j]);
		}
	}
}
int main (){
 	int x,y;
 	int arr[100][100];
 	printf("moi ban nhap vao so hang va cot cua mang");
 	scanf("%d",&x);
 	printf("moi ban nhap vao so hang va cot cua mang");
 	scanf("%d",&y);
 	matrix(arr,x,y);

 	return 0;
}
