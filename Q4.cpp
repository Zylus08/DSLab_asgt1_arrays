// a.Reverse the Elements of an Array

#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// b.Find the Matrix Multiplication
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    // Check if multiplication is possible
    if (colsA != rowsB) {
        throw invalid_argument("Matrix multiplication not possible: columns of A must match rows of B.");
    }

    // Initialize result matrix with zeros
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    // Matrix multiplication logic
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    try {
        vector<vector<int>> product = multiplyMatrices(A, B);

        cout << "Matrix Multiplication Result:" << endl;
        for (const auto& row : product) {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

// c.Transpose of a Matrix in C++
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            transposed[j][i] = matrix[i][j];

    return transposed;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> transposed = transposeMatrix(matrix);

    cout << "Transposed Matrix:" << endl;
    for (const auto& row : transposed) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}