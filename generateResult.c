#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int a[], int);
void selectionSort(int a[],int);
void insertionSort(int a[],int);
void print(int a[], int);
void generate_average_case(int t[],int n);
void generate_worst_case(int t[],int n);
void border(char *,int);
double getRunTime(void (*fun_ptr)(int a[],int),int a[],int);
void copy(int *a,int *b,int );

int main()
{
	int size[] = {10,100,1000,5000,10000,20000,50000,70000,100000};
	int *arr,i,j,k;
	FILE * fptr = fopen("points.txt", "w");
	void (*sort[3])(int a[], int);
	sort[0] = &bubbleSort;
	sort[1] = &selectionSort;
	sort[2] = &insertionSort;
	char *case_name[]={"Worst Case", "Average Case", "Best Case"};
	void (*generate_test_case[2])(int a[],int n);
	generate_test_case[0]= &generate_worst_case;
	generate_test_case[1]= &generate_average_case; 
	border("*",78);
	printf("%-10sCase Type\t\tBubbleSort\tSelectionSort\tInsertionSort\n","InputSize");
	border("*",78);
	for(i=0;i<sizeof(size)/sizeof(size[0]);i++){
		printf("%d\n",size[i]);
		int *arr=(int*)malloc(sizeof(int)*size[i]);
		fprintf(fptr,"%d\n",size[i]);
		for(j=0;j<3;j++){
			int *cpyarr= (int*)malloc(sizeof(int)*size[i]);
			if(j!=2)
				(*generate_test_case[j])(arr,size[i]);
			printf("%-10s%-15s\t", " ", case_name[j]);
			for(k=0;k<3;k++){
				if(j!=2){
					cpyarr=(int*)malloc(sizeof(int)*size[i]);
					copy(cpyarr,arr,size[i]);
				}
				double t = getRunTime(sort[k],cpyarr,size[i]);
				fprintf(fptr, "%f ",t);
				printf("%f\t",t);
				//print(cpyarr,size[i]);
			}
			printf("\n");
			fprintf(fptr, "\n");
		}
		border("-",78);
	}
	close(fptr);
	return 0;
}

void copy(int *a,int *b,int size){
	int i;
	for(i=0;i<size;i++){
		a[i]=b[i];
	}
}

double getRunTime(void (*fun_ptr)(int a[],int n), int a[], int n){
	clock_t exe_t = clock();
	(*fun_ptr)(a,n);
	return (double)(clock() - exe_t) / CLOCKS_PER_SEC;
}

void generate_worst_case(int nums[],int n){
	int i;
	for(i=0;i<n;i++)
		nums[i] = n - i;
}

void generate_average_case(int nums[],int n){
	int i;
	for(i=0;i<n;i++)
		nums[i] = rand();
}

void generate_best_case(int nums[],int n){
	int i;
	for(i=0;i<n;i++){
		nums[i] = i+1;
	}	
}

void insertionSort(int a[],int size){
	int i,j,n;
	for(i=1; i < size; i++){
		j = i; 
		n = a[i];
		while(j != 0 && a[j-1] > n){
			a[j] = a[j-1];
			j--;
		}
		a[j] = n;
	}	
}

void bubbleSort(int a[], int size){
	int i,j;
	for(i=0;i<size - 1; i++){
		short is_sorted = 1;
		for(j=0; j< size-i-1 ;j++ ){
			if(a[j] > a[j+1]){
				int d = a[j];
				a[j] = a[j+1];
				a[j+1] = d;
				is_sorted = 0;
			}
		}
		if(is_sorted)
			break;
	}
}

void selectionSort(int a[], int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(a[i]>a[j]){
				int d=a[i];
				a[i]=a[j];
				a[j]=d;
			}
		}
	}
}

void print(int a[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void border(char p[], int n){
	int i;
	for( i=0;i<n;i++){
		printf("%s", p);
	}
	printf("\n");
}
