/*
    Name: Raggav Subramani  
    Registration Number: 20BCT0127
    Purpose: To implement binary search algorithm to display student details
*/

#include <iostream>
#include <string>

using namespace std;
const int MAX = 10; //Declaring MAX value

class student_data{//Declaring class
public: 
    /* 
        This class is used to store student details as a class whose objects are cgpa, name and registration number.
    */
    int reg_no;
    string name;
    float cgpa;
};

int read_details(student_data details[]) { //Used to read student details
    printf("Enter registration number of student(Input -1 for last input):\n");
    int i = 0;
    cin >> details[i].reg_no;
    while (details[i].reg_no != -1) {
        //Input until registration number becomes -1
        cout << "Student name:" << endl;
        cin >> details[i].name;
        cout << "Student CGPA:" << endl;
        cin >> details[i++].cgpa;
        cout << endl
             << "Next Student details:" << endl;
        cout << "Enter Registration Number:" << endl;
        cin >> details[i].reg_no;
    }
    return i; //Returning length of details array
}

void sort_details(student_data arr[], int N){
    //Sorting array based on registration number using insertion sort algorithm
    int key;
    for (int i = 1; i < N; i++) {
        key = arr[i].reg_no;
        while (i > 0 && arr[i - 1].reg_no > key){
            student_data temp = arr[i];
            arr[i] = arr[i - 1];
            arr[(i--) - 1] = temp;
        }
    }
}

int search_details(student_data details[], int n)
{
    /*
       Implementing binary search algorithm on the array to search for registration 
       number and displaying name and cgpa corresponding to that registration number.
    */
    int number_to_search;
    cout << "\nInput Registration Number to be searched for:" << endl;
    cin >> number_to_search;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (details[middle].reg_no == number_to_search)
            return middle;
        else if (details[middle].reg_no < number_to_search)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}

int main()
{
    student_data details[MAX];
    int n;
    n = read_details(details);              //Reading details
    sort_details(details, n);               //sorting details
    int found = search_details(details, n); //searching for registration number
    if (found != -1)
    { //if found prints details
        cout << "Details:\nName:" << details[found].name << endl;
        cout << "CGPA: " << details[found].cgpa << endl;
    }
    else //else it returns element not found
        cout << "Element not found" << endl;
    return 1;
}
