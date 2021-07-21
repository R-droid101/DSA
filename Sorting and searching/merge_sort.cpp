/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To implement merge sort algorithm
*/

#include <iostream>
using namespace std;
const int MAX = 15;

int count=0;

void input(int arr[], int N) { //Function to input array elements from user
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void output(int arr[], int N) { //Function to output an array 
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int m, int r) { //Function to sort and merge two arrays
    int n1=m-l+1; //n1 represents the number of elements in the first half of array
    int n2=r-m;   //n2 represents the number of elements in the second half of array
    int A[n1], B[n2];
    for(int i=0;i<n1;i++) //Stores first half of array
        A[i]=arr[i+l];
    for(int i=0; i<n2; i++) //Stores second half of array
        B[i]=arr[m+i+1];
    int i=0,j=0,k=l;  //Variables to iterate, i for first half and j for second half
    while(i<n1 && j<n2){ 
        if(A[i]<=B[j]){ //Merging after checking which is the bigger number
            arr[k]=A[i++];
            count++;
        }
        else{
            arr[k]=B[j++];
            count++;
        }
        k+=1;
    }
    while(i<n1) //Copying remaining values of first array into the final array
        arr[k++]=A[i++];
    while(j<n2) //Copying remaining values of second array into the final array
        arr[k++]=B[j++];
}

void mer_sort(int arr[], int l, int r) { 
    /*
        Function that recursively calls anad splits the array to perform merge sort
    */
    if(l>=r)
        return;
    int m=(l+r)/2; //Finding middle element
    mer_sort(arr,l,m); //Splitting array into two halves and performing merge sort recursively
    mer_sort(arr,m+1,r); 
    merge(arr,l,m,r); //Merging the two arrays to make it one array
}

int main() { //Main method to manage flow of control
    int N, arr[MAX];
    cout << "Input number of elements" << endl;
    cin >> N; //Reading length of array from user
    cout << "Input array to be sorted:" << endl;
    input(arr, N); //Reading array elements from user
    cout << "Unsorted array:" << endl;
    output(arr, N); //Printing unsorted array
    mer_sort(arr, 0, N-1); //Performing merge sort on the array
    cout << "Array after merge sort:" << endl;
    output(arr, N); //Printing sorted array
    cout<<"\nNumber of comparisons:"<<count<<endl;
    return 1;
}