#include <stdlib.h>
#include "sort.h"

long int InsertionSort(Record* A, int n){
	int j;
	Record temp;
	long int count=0;
	for(int i=1;i<n;i++){
		j=i-1;
		temp=A[i];
		while(A[j].serialnumber>temp.serialnumber && j>=0){
			A[j+1]=A[j];
			count++;
			j--;
		}
		if(j!=-1)
			count++;
		A[j+1]=temp;
	}
	return count;
}

long int BubbleSort(Record* A, int n){
	Record temp;
	long int count=0;
	int swaps;
	for(int i=0;i<n;i++){
		swaps=0;
		for(int j=0;j<n-1-i;j++){
			count++;
			if(A[j].serialnumber>A[j+1].serialnumber){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				swaps=1;
			}
		}
		if(swaps==0)
			break;
	}
	return count;
}

long int SelectionSort(Record* A, int n){
	Record temp;
	long int count=0;
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			count++;
			if(A[min].serialnumber>A[j].serialnumber)
				min=j;
		}
		temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
	return count;
}
int Partition(Record * A, int n,long int* count){
	if(0!=n/2 && n-1!=0){
		if((A[n-1].serialnumber>A[n/2].serialnumber && A[n-1].serialnumber<A[0].serialnumber)||(A[n-1].serialnumber<A[n/2].serialnumber && A[n-1].serialnumber>A[0].serialnumber)){
			Record temp=A[0];
			A[0]=A[n-1];
			A[n-1]=temp;
		}
		if((A[n/2].serialnumber>A[n-1].serialnumber && A[n/2].serialnumber<A[0].serialnumber)||(A[n/2].serialnumber<A[n-1].serialnumber && A[n/2].serialnumber>A[0].serialnumber)){
			Record temp=A[0];
			A[0]=A[n/2];
			A[n/2]=temp;
		}
	}
	int pivot=A[0].serialnumber;
	int i=1;
	int j=n-1;
	Record temp;
	while(i<=j){
		while(A[i].serialnumber<pivot && i<=j){
			i++;
			*count=*count+1;
		}
		//*count=*count+1;
		while(A[j].serialnumber>pivot && i<=j){
			j--;
			*count=*count+1;
		}
		//*count=*count+1;
		if(i<j){
			temp.score=A[i].score;
			A[i].score=A[j].score;
			A[j].score=temp.score;
			temp.serialnumber=A[i].serialnumber;
			A[i].serialnumber=A[j].serialnumber;
			A[j].serialnumber=temp.serialnumber;
			i++;
			j--;
			*count=*count+1;
		}
		else break;
	}
	temp.score=A[0].score;
	A[0].score=A[j].score;
	A[j].score=temp.score;
	temp.serialnumber=pivot;
	A[0].serialnumber=A[j].serialnumber;
	A[j].serialnumber=temp.serialnumber;
	return j;
}
long int QuickSort(Record* A, int n){
	long int count=0;
	if(n<=1)
		return 0;
	if(n>1){
		int m=Partition(A,n,&count);
		count+=QuickSort(A,m);
		count+=QuickSort(A+m+1,n-m-1);
	}
	return count;
}

void Merge(Record* A,int n, Record* B,int p, Record* C, int q, long int* count){
	int i,j,k;
	for(i=0,j=0,k=0;i<p && j<q;){
		*count=*count+1;
		if(B[i].serialnumber < C[j].serialnumber){
			A[k].score=B[i].score;
			A[k].serialnumber=B[i].serialnumber;
			k++;
			i++;
		}
		else{
			A[k].score=C[j].score;
			A[k].serialnumber=C[j].serialnumber;
			k++;
			j++;
		}
	}
	if(i!=p){
		for(;i<p;i++){
			A[k].score=B[i].score;
			A[k].serialnumber=B[i].serialnumber;
			k++;
		}
	}
	if(j!=q){
		for(;j<q;j++){
			A[k].score=C[j].score;
			A[k].serialnumber=C[j].serialnumber;
			k++;
		}
	}
}
long int MergeSort(Record* A, int n){
	long int count=0;
	if(n<=1)
		return 0;
	int m=n/2,i;
	Record *B=(Record*)malloc(sizeof(Record)*m);
	for(i=0;i<m;i++){
		B[i].score=A[i].score;
		B[i].serialnumber=A[i].serialnumber;
	}
	Record* C=(Record*)malloc(sizeof(Record)*(n-m));
	for(int c=0;c<(n-m);c++,i++){
		C[c].score=A[i].score;
		C[c].serialnumber=A[i].serialnumber;
	}
	count+=MergeSort(B,m);
	count+=MergeSort(C,n-m);
	Merge(A,n,B,m,C,n-m,&count);
	free(B);
	free(C);
	return count;
}