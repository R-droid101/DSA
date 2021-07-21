/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To implement selection sort algorithm
*/

#include <iostream>
using namespace std;
const int MAX = 15;

int count=0;

void input(int arr[], int N){//Function to read array as input from user
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

void output(int arr[], int N){//Function to display array to user
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sel_sort(int arr[], int N){//Implementing selection sort algorithm to sort the array
    for (int i = 0; i< N; i++){
        int min = i;//Considering the value at i to be minimum
        for (int j = i+1; j < N; j++){
            ++count;
            if (arr[min] > arr[j])//If anything lesser than arr[min],
                min = j;          //Making that min value
        }
        int temp = arr[min];//Swapping value of arr[min] and arr[i]
        arr[min] = arr[i];  //so that minimum value goes to starting position
        arr[i] = temp;
    }
}

int main(){//Main function to call functions and manage flow of control
    int N, arr[MAX];
    cout << "Input number of elements" << endl;
    cin >> N;//Reading size of array
    cout << "Input array to be sorted:" << endl;
    input(arr, N);//Reading array elements
    cout << "Unsorted array:" << endl;
    output(arr, N);//Printing unsorted array
    sel_sort(arr, N);//Sorting array using selection array
    cout << "Array after selection sort:" << endl;
    output(arr, N);//Printing sorted array
    cout<<"\nNumber of comparisons:"<<count;
    return 1;
}