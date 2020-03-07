#include<stdio.h>
#include<time.h>

void selectionsort(int *,int start,int minpos);

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void selectionsort(int a[],int start,int n) //sort array from start to n-1//
{
	int i,minpos;

    if(start>n-1)
        return ;
	
	//locate minimum element and move to start of segment//
    minpos = start;
    for(i=start+1 ; i < n ; i++)
    {
        if(a[i]<a[minpos])
           {
                minpos = i;
           }
    
    }
    
    swap(&a[start],&a[minpos]);

    selectionsort(a,start+1,minpos);
}
	


void toSort()
{
    int arr[10],n,i;
	printf("\nEnter no. of elements : ");
	scanf("%d",&n);
	printf("\nEnter the array elements : ");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}

    i = 0; 
    selectionsort(arr,i,n);

    printf("\nThe sorted array is : \n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d -> ",arr[i]);
	}
}

int main()
{
	clock_t start,end; 
    start = clock(); 
    toSort(); 
    end = clock(); 
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC; 
  
    printf("Slection Sort using recursion took  %f seconds to execute \n", time_taken); 
    return 0; 
}