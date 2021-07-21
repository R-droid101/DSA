/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To implement bubble sort algorithm
*/

#include <iostream>
using namespace std;
const int MAX = 15;

int count=0;

void input(int arr[], int N){//Function to input array
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void output(int arr[], int N){//Function to output array
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bub_sort(int arr[], int N){//Implementing bubble sort algorithm
    for (int i = 0; i < N - 1; i++){
    int flag = 0;//Flag variable to improve efficiency of code
        for (int j = 0; j < N - i - 1; j++){
            count++;
            if (arr[j] > arr[j + 1]){//Checking condition and enabling swapping of elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;//Flag=1 when a swap happens
            }
        }
        if (flag == 0)//If no swap happens in the inner loop it means array is sorted
            break;
    }
}

int main(){//Main program to call functions
    int N, arr[MAX];
    cout << "Input number of elements" << endl;
    cin >> N;//Reading number of elements of array from user
    cout << "Input array to be sorted:" << endl;
    input(arr, N);//Reading array from user
    cout << "Unsorted array:" << endl;
    output(arr, N);//Printing unsorted array
    bub_sort(arr, N);//Sorting array
    cout << "Array after bubble sort:" << endl;
    output(arr, N);//Printing sorted array
    cout<<"\nNumber of comparisons:"<<count<<endl;
    return 1;//Returning from function
}