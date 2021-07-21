#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct student{
    int reg_no;
    char name[100];
    float cgpa;
} student_data;

int read_details(student_data details[]){
    printf("Enter registration number of student(Input -1 for last input):\n");
    int i = 0;
    scanf("%d", &details[i].reg_no);
    while (details[i].reg_no != -1){
        printf("Student name:\n");
        scanf("%s", details[i].name);
        printf("Student CGPA:\n");
        scanf("%f", &details[i++].cgpa);
        printf("\nNext Student details:\n");
        printf("Enter Registration Number:\n");
        scanf("%d", &details[i].reg_no);
    }
    return i;
}

void sort_details(student_data details[], int n){
    int min;
    student_data temp;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (details[j].reg_no < details[min].reg_no)
                min = j;
        }
        temp = details[i];
        details[i] = details[min];
        details[min] = temp;
    }
}

int search_details(student_data details[], int n){
    int x;
    printf("Input Registration Number to be searched for:\n");
    scanf("%d", &x);
    int s = 0, e = n - 1;
    while (s <= e){
        int m = (s + e) / 2;
        if (details[m].reg_no == x)
            return m;
        else if (details[m].reg_no < x)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int main(){
    student_data details[MAX];
    int n;
    n = read_details(details);
    sort_details(details, n);
    //print_details(details,n);
    int found = search_details(details, n);
    if (found != -1)
        printf("Details:\nName: %s\nCGPA: %.2f", details[found].name, details[found].cgpa);
    else
        printf("Element not found");
}