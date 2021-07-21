/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To implement quick sort algorithm
*/

#include <iostream>
using namespace std;
const int MAX = 15;

int count=0;

void input(int arr[], int N) {//Function to read array elements from user
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void output(int arr[], int N) {//Function to display an array of length N
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b) {//Function to swap two elements a and b
    int t = *a;
    *a = *b;
    *b = t;
}

int split(int arr[], int first, int last) {//Function to split the array to sort it
    int pivot = arr[last];//Stores last element as pivot
    int i = first - 1;   
    for (int j = first; j < last; j++) {
        count++;
        if (arr[j] < pivot) {  //If arr[j] is less than pivot then i is increased
            i += 1;
            swap(&arr[i], &arr[j]);// and values at arr[i] and arr[j] is swapped
        }
    }
    swap(&arr[i + 1], &arr[last]);// At the end arr[i+1] and arr[last] is swapped as pivot element is brought
    return (i + 1);
}

void quick_sort(int arr[], int first, int last){//Function to sort the array using quick sort algorithm
    if (first < last){
        int index = split(arr, first, last);
        quick_sort(arr, first, index - 1);//Recursively using after splitting the array
        quick_sort(arr, index + 1, last);
    }
}

int main() {
    int N, arr[MAX];
    cout << "Input number of elements" << endl;
    cin >> N; //Reading length of array
    cout << "Input array to be sorted:" << endl;
    input(arr, N); //Input array elements from user
    cout << "Unsorted array:" << endl;
    output(arr, N); //Output unsorted array
    quick_sort(arr, 0, N - 1); //Sort array using quick sort
    cout << "Array after quick sort:" << endl;
    output(arr, N); //Output sorted array
    cout<<"\nNumber of comparisons:"<<count<<endl;
    return 1;
}