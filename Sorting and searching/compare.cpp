/*
    Name: Raggav Subramani
    Registration number: 20BCT0127
    Purpose: To compare performance of different sorting algorithms
*/

#include <iostream>
using namespace std;
const int MAX = 100;

int count = 0;

void input(int arr[], int N) { //Function to create array from based on size N
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100; //Using rand() function to generate random numbers for array 
}

void copy(int arr[], int decoy[], int N) { //Function to create instances of an array to use for different 
    for (int i = 0; i < N; i++) {          //sorting methods
        decoy[i] = arr[i];
    }
}

void swap(int *a, int *b) { //Function to swap two values
    int t = *a;
    *a = *b;
    *b = t;
}

void bubSort(int arr1[], int N) { //Function implementing bubble sort
    int arr[N];
    copy(arr1, arr, N);
    count = 0;
    for (int i = 0; i < N - 1; i++) {
    int flag = 0;
        for (int j = 0; j < N - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    cout << "Bubble Sort:\t" << count << endl;
}

void insSort(int arr1[], int N) { //Function implementing insertion sort
    int arr[N];
    copy(arr1, arr, N);
    count = 0;
    int key;
    for (int i = 1; i < N; i++) {
        key = arr[i];
        while (i > 0  && arr[i - 1] > key && ++count) {
            swap(&arr[i], &arr[i - 1]);
            i--;
        }
    }
    cout << "Insertion Sort:\t" << count << endl;
}

void merge(int arr[], int l, int m, int r) { //Function to merge to arrays for merge sort implementation
    int n1 = m - l + 1;
    int n2 = r - m;
    int A[n1], B[n2];
    for (int i = 0; i < n1; i++)
        A[i] = arr[i + l];
    for (int i = 0; i < n2; i++)
        B[i] = arr[m + i + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            count++;
            arr[k] = A[i++];
        }
        else
        {
            count++;
            arr[k] = B[j++];
        }
        k += 1;
    }
    while (i < n1)
        arr[k++] = A[i++];
    while (j < n2)
    {
        arr[k++] = B[j++];
    }
}

void merSort(int arr[], int l, int r) { //Function to implement merge sort
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merSort(arr, l, m);
    merSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int split(int arr[], int first, int last) { 
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++) {
        count++;
        if (arr[j] < pivot) {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return (i + 1);
}

void quickSort(int arr[], int first, int last) { //Function to implement quick sort
    if (first < last) {
        int index = split(arr, first, last);
        quickSort(arr, first, index - 1);
        quickSort(arr, index + 1, last);
    }
}

void selSort(int arr1[], int N) { // Function to implement selection sort
    int arr[N];
    copy(arr1, arr, N);
    count = 0;
    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            count++;
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
    cout << "Selection Sort:\t" << count << endl;
}

int main() { //Main function to control flow of execution and help compare efficiency of sorting algorithms
    int N=5;
    //cout << "Input size of array:" << endl;
    //cin >> N; //Reading size of array from user
    int i=0;
    while(i++<9){
        cout<<"\nSize of array:"<<N<<endl;
        int arr[N];
        input(arr, N); // Creating array
        cout << "\nSorting method:\t Number of comparisons" << endl;
        bubSort(arr, N); //Printing number of comparisons in bubble sort
        insSort(arr, N); //Printing number of comparisons in insertion sort
        selSort(arr, N); //Printing number of comparisons in selection sort
        /*
            Count is made 0 for the next two as both are recursive methods. It is not done in the main
            function for the above 3 as they are done within their respective functions as they are not recursively
            called. Due to recursive nature of quick and merge sort count value will get reset every time and 
            will give the wrong output. The same logic follows for instances of the array.    
        */
        count = 0; 
        int merge_arr[N];
        copy(arr, merge_arr, N); //Creating instance of original array
        merSort(merge_arr, 0, N - 1);
        cout << "Merge Sort:\t" << count << endl; //Prints number of comparisons in merge sort
        count = 0;
        int quick_arr[N];
        copy(arr, quick_arr, N);
        quickSort(quick_arr, 0, N - 1);
        cout << "Quick Sort:\t" << count << endl; //Prints number of comparisons in quick sort
        if(i%2==1)
        N=N*2;
        else
        N=N*5;
    }
}