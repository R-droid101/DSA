/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Purpose: To find square root of a number using binary search
*/

#include <iostream>

using namespace std;

int sqr_root(int num){
    int sqrt;
    if (num==0 || num==1)
    return num;
    int s=1, e=num, mid=0;
    while(s<=e){
        mid=(s+e)/2;
        if(mid*mid == num)
        return mid;

        else if(mid*mid < num){
            s=mid+1;
            sqrt=mid;
        }
        else
        e=mid-1;
    }
    return sqrt;
}

int main(){
    int num;
    cout<<"Input number to find square root"<<endl;
    cin>>num;
    cout<<"Square root of number was found to be: "<<sqr_root(num)<<endl;
    return 1;
}