#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void fix(string &s)
{
    // to remove spaces and convert it all to lower case
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void create_new_mat(int **mat, int size)
{
    for(int i = 0; i < size; i++)
    {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = 0;
        }
    }
}

int subt(int a, int b)
{ // utility function to perform modulo subtraction
    if(a > b)
    {
    cout << (a-b) << endl;
    return (a-b);
    }
    else 
    {
        cout << b-a << endl;
    return (b-a);
    }
}

void to_adj_mat(int **mat, int size, string s, int len)
{ // prepares the adjaceny matrix of the given string with the required conditions
    string temp = s;
    cout << temp << endl;
    sort(s.begin(), s.end()); // sorts the string 
    char prev = s[0];
    cout << s[0];
    for(char a : s)
    { // printing out the characters
        if(a == prev)
        { // if repeated character exists, skip it
            prev = a;
            continue;
        }
        
        cout << a;
        prev = a;
    }
    cout << endl;
    cout << s << endl;
    // start creating the adjacency matrix
    for (int i = 1; i < len - 1; i++)
    {
        // checking in the sorted string first and avoiding repeated letters
        int previous = s[i-1] - 'a';
        int current = s[i] - 'a';
        int next = s[i+1] - 'a';
        
        cout << current <<"Cur" << endl;
        cout << previous << "Prev" << endl;
        
        if(previous != current)
        {
            mat[previous][current] = subt(current, previous);
            mat[current][previous] = subt(current, previous);
        }
        if(next != current)
        {
            mat[next][current] = subt(current, next);
            mat[current][next] = subt(current, next);
        }
        
        // checking the original unsorted string and avoiding repeated letters
        int prev_unsort = temp[i-1] - 'a';
        int curr_unsort = temp[i] - 'a';
        int next_unsort = temp[i+1] - 'a';
        
        cout << prev_unsort << "prevun" << endl;
        cout << curr_unsort << "Currun" << endl;
        
        if(prev_unsort != curr_unsort)
        {
            mat[prev_unsort][curr_unsort] = subt(curr_unsort, prev_unsort);
            mat[curr_unsort][prev_unsort] = subt(curr_unsort, prev_unsort);
        }
        if(next_unsort != curr_unsort)
        {
            mat[next_unsort][curr_unsort] = subt(curr_unsort, next_unsort);
            mat[curr_unsort][next_unsort] = subt(curr_unsort, next_unsort);
        }
    }
    cout << "Not come?" << endl;
}

void print_adj_list(int **mat, int size)
{
    cout << endl;
    string s; // string to store result
    bool check = false; // to keep checking if any characters exist or not
    // printing the adjacency matrix as a list
    for (int i = 0; i < size; i++) {
        s = (char) i + 'a'; // starts the first string
        s += ": ";
        check = false;
        for (int j = 0; j < size; j++) {
            if (mat[i][j]) {
                check = true;
                s += (char) j + 'a'; // continues making the string
                s += ", "; // separated by a comma and a space
            }
        }
        if (check) // if anything exists within it only then it prints
            cout << s << endl;
    }
}

void print(int **mat, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        cout << mat[i][j] << " ";
    }
    cout << endl;
}

int main()
{
    string str;
    getline(cin, str); // reading name from the user to create alphanet
    int len;
    len = str.length();
    int **mat = new int*[26];
    
    fix(str); // to fix the string 
    create_new_mat(mat, 26);
    to_adj_mat(mat, 26, str, len);
    print_adj_list(mat, 26);

    return 0;
}