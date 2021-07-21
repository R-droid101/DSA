/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To implement insertion sort algorithm
*/

#include <iostream>
using namespace std;
const int MAX = 15;

int count=0;

void input(int arr[], int N){//Function to read input from user
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void output(int arr[], int N){//Function to display array to the user
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void ins_sort(int arr[], int N){//Function to implement insertion sort algorithm to sort an array
    int key;
    for (int i = 1; i < N; i++){
        key = arr[i];
        while (i > 0 && arr[i - 1] > key && count++){//Checks condition and places the element in it's respective position
            int temp = arr[i];//Code to swap data
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}

int main(){//Main function to execute the functions
    int N, arr[MAX];
    cout << "Input number of elements" << endl;
    cin >> N;//Reading number of array elements
    cout << "Input array to be sorted:" << endl;
    input(arr, N);//Reading array from user
    cout << "Unsorted array:" << endl;
    output(arr, N);//Printing unsorted array
    ins_sort(arr, N);//Performing insertion sort on the printed array
    cout << "Array after insertion sort:" << endl;
    output(arr, N);//Printing sorted array
    cout<<"\nNumber of comparisons:"<<count<<endl;
    return 1;
}