#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

#define alpha_len 26

static string modif_string(string s)
{
    cout << s << endl;
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); // remove spaces from the string
    cout << s << endl;
    transform(s.begin(), s.end(), s.begin(), ::tolower); //  converting it to lower case
    cout << s << endl;
    return s;
}

void new_matrix(int** mat, int size)
{
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = 0;
        }
    }
    return;
}

void print_matrix(int **matrix, int size) {
    // Prints a matrix of dimensions: sizexsize
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << std::setw(2) << matrix[i][j] << ", ";
        std::cout << "\n";
    }
    return;
}

void adj_mat(int **mat, int size, string s, int len)
{
    string temp = s;
    cout << temp << endl;
    sort(s.begin(), s.end()); // sorting letters within string
    cout << s << endl;
    for (char a : s)
    cout << a << " ";

    for (int i = 1; i < len-1; i++)
    {
        int current = (s[i] - 'a'); // converting character to integers on sorted string
        int next = (s[i+1] - 'a'); 
        int previous = (s[i-1] - 'a');

        if (previous != current)
        { // to remove repitive letters
            mat[previous][current] = previous + 1;
            mat[current][previous] = current + 1;
        }

        if (next != current)
        { // to remove repitive letters
            mat[next][current] = next + 1;
            mat[current][next] = current + 1;
        }

        // to create adjacency matrix
        int current_pos = (temp[i] - 'a');
        int next_pos = (temp[i+1] - 'a');
        int previous_pos = (temp[i-1] - 'a'); 

        if (previous_pos != current_pos)
        {
            mat[previous_pos][current_pos] = previous_pos + 1;
            mat[current_pos][previous_pos] = current_pos + 1;
        }

        if (next_pos != current_pos)
        {
            mat[next_pos][current_pos] = next_pos + 1;
            mat[current_pos][next_pos] = current_pos + 1;
        }
    }
}

// int** bfs(int** matrix, int size, int start) {
//     // standard bfs
//     int** adjacency_matrix = new int*[size];
//     create_empty_matrix(adjacency_matrix, size);

//     bool visited[size];

//     for (int i = 0; i < size; i++)
//         visited[i] = false;

//     visited[start] = true;

//     std::queue<int> q;
//     q.push(start);

//     int current;

//     while (!q.empty()) {
//         current = q.front();
//         q.pop();

//         for (int a = 0; a < size; a++) {
//             if (matrix[current][a] != 0 && !visited[a]) {
//                 q.push(a);
//                 visited[a] = true;
//                 adjacency_matrix[current][a] = matrix[current][a];
//                 adjacency_matrix[a][current] = matrix[current][a];
//             }
//         }
//     }

//     return adjacency_matrix;
// }

void adj_list(int**mat, int size) {
    cout << endl;
    string s;
    bool check = false;
    for (int i = 0; i < size; i++) {
        s = (char) i + 'a';
        s += ": ";
        check = false;
        for (int j = 0; j < size; j++) {
            if (mat[i][j]) {
                check = true;
                s += (char) j + 'a';
                s += ", ";
            }
        }
        if (check)
            cout << s << endl;
    }
}

int main() {
    string name;

    getline(cin, name);
    name = modif_string(name);
    int size = name.length();

    int **mat = new int*[26];
    new_matrix(mat, 26);
    adj_mat(mat, 26, name, size);

    cout << "Adjacency \n";
    adj_list(mat, 26);
    // print_matrix(matrix, alpha_len);

    // int** adj_matrix = bfs(mat, (int) 26, name[0] - 'a');
    // std::cout << "\nBFS matrix: \n";
    // print_matrix(adj_matrix, 26);

    // std::cout << "\nBFS Adj List: \n";
    // print_adj_list(adj_matrix, alpha_len);
    return 0;
}
