#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// displayMatrix()

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


// readMatrix()

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


// transposeMatrix()

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];   // flip row/column indices
        }
    }
}


// addMatrices()

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// multiplyMatrices()

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}


// pauseForNext()

void pauseForNext(string nextPartLabel) {
    cout << "\nPress Enter to continue to " << nextPartLabel << "...";
    cin.ignore();   // clears leftover newline from the previous cin >>
    cin.get();      // waits for the user to press Enter
}

// main()

int main() {
    // ---------------- PART A: TRANSPOSE ----------------
    cout << "=== PART A: TRANSPOSE ===" << endl;

    int matrixA[10][10], transposed[10][10];
    int rowsA, colsA;

    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(matrixA, rowsA, colsA);
    transposeMatrix(matrixA, transposed, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rowsA, colsA);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, colsA, rowsA);  

    pauseForNext("PART B: ADD TWO MATRICES");

    // ---------------- PART B: ADDITION ----------------
    cout << "\n=== PART B: ADD TWO MATRICES ===" << endl;

    int matrixB1[10][10], matrixB2[10][10], sumResult[10][10];
    int rowsB, colsB;

    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    cout << "\nEnter Matrix 1:" << endl;
    readMatrix(matrixB1, rowsB, colsB);

    cout << "\nEnter Matrix 2:" << endl;
    readMatrix(matrixB2, rowsB, colsB);

    addMatrices(matrixB1, matrixB2, sumResult, rowsB, colsB);

    cout << "\nSum of the two matrices:" << endl;
    displayMatrix(sumResult, rowsB, colsB);

    pauseForNext("PART C: MULTIPLY TWO MATRICES");

    // ---------------- PART C: MULTIPLICATION ----------------
    cout << "\n=== PART C: MULTIPLY TWO MATRICES ===" << endl;

    int matrixC1[10][10], matrixC2[10][10], productResult[10][10];
    int m, n1, n2, p;

    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n1;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(matrixC1, m, n1);

    cout << "\nEnter rows of Matrix B (must equal N = " << n1 << "): ";
    cin >> n2;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    // Validate that multiplication is actually possible before proceeding
    if (n2 != n1) {
        cout << "\nError: Cannot multiply. Columns of A (" << n1
             << ") must equal rows of B (" << n2 << ")." << endl;
        return 0;
    }

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(matrixC2, n2, p);

    multiplyMatrices(matrixC1, matrixC2, productResult, m, n1, p);

    cout << "\nProduct of A x B:" << endl;
    displayMatrix(productResult, m, p);

    return 0;
}
