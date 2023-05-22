#include <iostream>
#include <vector>

using namespace std;

// Divide a matrix into four sub-matrices
void divide_matrix(vector<vector<int>>& A, vector<vector<int>>& A11, vector<vector<int>>& A12, vector<vector<int>>& A21, vector<vector<int>>& A22) {
    int n = A.size();
    int m = A[0].size();
    int half_n = n/2;
    int half_m = m/2;
    
    for (int i=0; i<half_n; i++) {
        for (int j=0; j<half_m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][half_m+j];
            A21[i][j] = A[half_n+i][j];
            A22[i][j] = A[half_n+i][half_m+j];
        }
    }
}

// Add two matrices
vector<vector<int>> matrix_add(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return C;
}

// Subtract two matrices
vector<vector<int>> matrix_subtract(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    return C;
}

// Multiply two matrices using the Divide and Conquer algorithm
vector<vector<int>> matrix_multiply_divide_conquer(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));
    
    // Base case: A and B are 1x1 matrices
    if (n == 1 && m == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    
    // Divide each matrix into four sub-matrices
    vector<vector<int>> A11(n/2, vector<int>(m/2));
    vector<vector<int>> A12(n/2, vector<int>(m/2));
    vector<vector<int>> A21(n/2, vector<int>(m/2));
    vector<vector<int>> A22(n/2, vector<int>(m/2));
    divide_matrix(A, A11, A12, A21, A22);
    
    vector<vector<int>> B11(n/2, vector<int>(m/2));
    vector<vector<int>> B12(n/2, vector<int>(m/2));
    vector<vector<int>> B21(n/2, vector<int>(m/2));
    vector<vector<int>> B22(n/2, vector<int>(m/2));
    divide_matrix(B, B11, B12, B21, B22);
}
int main() {
    // Create two matrices A and B
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};

    // Multiply matrices A and B using the Divide and Conquer algorithm
    vector<vector<int>> C = matrix_multiply_divide_conquer(A, B);

    // Print the resulting matrix C
    cout << "Resulting matrix C:" << endl;
    for (int i=0; i<C.size(); i++) {
        for (int j=0; j<C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
