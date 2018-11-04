#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sort.h"

int main(){
	int n;
	scanf("%d",&n);
	Record *A1=(Record*)malloc(sizeof(Record)*n);
	Record *A2=(Record*)malloc(sizeof(Record)*n);
	Record *A3=(Record*)malloc(sizeof(Record)*n);
	Record *A4=(Record*)malloc(sizeof(Record)*n);
	Record *A5=(Record*)malloc(sizeof(Record)*n);
	for(int i=0;i<n;i++){
		scanf("%ld %d",&A1[i].serialnumber,&A1[i].score);
	}
	for(int i=0;i<n;i++){
		A2[i].serialnumber=A1[i].serialnumber;
		A3[i].serialnumber=A1[i].serialnumber;
		A4[i].serialnumber=A1[i].serialnumber;
		A5[i].serialnumber=A1[i].serialnumber;
		A2[i].score=A1[i].score;
		A3[i].score=A1[i].score;
		A4[i].score=A1[i].score;
		A5[i].score=A1[i].score;
	}
	struct timespec start,end;
	long int count;
	clock_gettime(CLOCK_REALTIME,&start);
	count=InsertionSort(A1,n);
	clock_gettime(CLOCK_REALTIME,&end);
	// for(int i=0;i<n;i++){
	// 	printf("%ld %d\n",A1[i].serialnumber,A1[i].score);
	// }
	printf("InsertionSort: %ld %lf\n",count,((end.tv_sec-start.tv_sec)+((end.tv_nsec-start.tv_nsec)*pow(10,-9))));
	clock_gettime(CLOCK_REALTIME,&start);
	count=BubbleSort(A2,n);
	clock_gettime(CLOCK_REALTIME,&end);
	// for(int i=0;i<n;i++){
	// 	printf("%d %d\n",A[i].serialnumber,A[i].score);
	// }
	printf("BubbleSort: %ld %lf\n",count,((end.tv_sec-start.tv_sec)+((end.tv_nsec-start.tv_nsec)*pow(10,-9))));
	clock_gettime(CLOCK_REALTIME,&start);
	count=SelectionSort(A3,n);
	clock_gettime(CLOCK_REALTIME,&end);
	// for(int i=0;i<n;i++){
	// 	printf("%d %d\n",A[i].serialnumber,A[i].score);
	// }
	printf("SelectionSort: %ld %lf\n",count,((end.tv_sec-start.tv_sec)+((end.tv_nsec-start.tv_nsec)*pow(10,-9))));
	clock_gettime(CLOCK_REALTIME,&start);
	count=MergeSort(A5,n);
	clock_gettime(CLOCK_REALTIME,&end);
	// for(int i=0;i<n;i++){
	// 	printf("%d %d\n",A[i].serialnumber,A[i].score);
	// }
	printf("MergeSort: %ld %lf\n",count,((end.tv_sec-start.tv_sec)+((end.tv_nsec-start.tv_nsec)*pow(10,-9))));
	clock_gettime(CLOCK_REALTIME,&start);
	count=QuickSort(A4,n);
	clock_gettime(CLOCK_REALTIME,&end);
	// for(int i=0;i<n;i++){
	// 	printf("%d %d\n",A[i].serialnumber,A[i].score);
	// }
	printf("QuickSort: %ld %lf\n",count,((end.tv_sec-start.tv_sec)+((end.tv_nsec-start.tv_nsec)*pow(10,-9))));
	
}