#include <stdio.h>
#include<sys/time.h>
#include<stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = 0;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertion_sort(int arr[], int n) {
    for(int index = 1; index < n; index++) {
	    int new_index = index;
        int new_element = arr[index];
	    
	   //for finding the correct position in the sorted array
	    while(new_index > 0 && arr[new_index - 1] > new_element) {
	        arr[new_index] = arr[new_index - 1];
	        new_index--;
       	}
	
	   //placing the new value to at the right position.
      	arr[new_index] = new_element;
    }
}

void random_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = rand();
    }
    
    // for calculating the time taken for sorting 
    
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    insertion_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting random %d elements is : %ld\n", n, endtime - starttime);
    
}


// function for generating inputs in sorted order

void sorted_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = i;
    }
    
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    insertion_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting sorted %d elements is : %ld\n", n, endtime - starttime);
    
}

// function for generating inputs in reversed order

void reverse_inputs(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        
        arr[i] = n - i;
    }
    
    struct timeval ti;
    gettimeofday(&ti , NULL);
    long starttime = ti.tv_sec *1000LL + ti.tv_usec/1000;

    insertion_sort(arr , n);
    
    gettimeofday(&ti , NULL);
    long endtime=ti.tv_sec *1000LL + ti.tv_usec/1000;
    
    printf("Time Taken for sorting reversed %d elements is : %ld\n", n, endtime - starttime);
    
}

int main()
{
    int n = 0 ;
    printf("Enter array size : \n");
    scanf("%d",&n);
    int arr[n];
    
    // calling the function for generating random inputs
    random_inputs( arr, n);
    
    // calling the function for generating inputs in sorted order
    sorted_inputs( arr, n);
    
    // calling the function for generating inputs in reversed order
    reverse_inputs( arr, n);


    return 0;
}
