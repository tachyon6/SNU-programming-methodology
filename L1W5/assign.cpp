#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;

void read_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size) {
    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < col_size; ++j) {
            cin >> mat[i][j];
        }
    }
}

void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size) {
    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < col_size; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_mul(int mat_A[MAX_SIZE][MAX_SIZE], int mat_A_row_size,
                int mat_A_col_size, int mat_B[MAX_SIZE][MAX_SIZE],
                int mat_B_row_size, int mat_B_col_size,
                int scores[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < mat_A_row_size; ++i) {
        for (int j = 0; j < mat_B_col_size; ++j) {
            scores[i][j] = 0;
            for (int k = 0; k < mat_A_col_size; ++k) {
                int resultA = mat_A[i][k];
                int resultB = mat_B[k][j];
                if ((resultA == 1 && resultB == 3) || (resultA == 2 && resultB == 1) || (resultA == 3 && resultB == 2)) {
                    scores[i][j]++;
                } else if (resultA == resultB) {
                } else {
                    scores[i][j]--;
                }
            }
        }
    }
}

int main() {
    int mat_A_row_size, mat_A_col_size;
    int mat_B_row_size, mat_B_col_size;

    int mat_A[MAX_SIZE][MAX_SIZE];
    int mat_B[MAX_SIZE][MAX_SIZE];
    int scores[MAX_SIZE][MAX_SIZE] = {
        0,
    };

    cin >> mat_A_row_size >> mat_A_col_size;
    cin >> mat_B_row_size >> mat_B_col_size;

    read_matrix(mat_A, mat_A_row_size, mat_A_col_size);
    read_matrix(mat_B, mat_B_row_size, mat_B_col_size);

    cout << "[A matrix]" << endl;
    print_matrix(mat_A, mat_A_row_size, mat_A_col_size);
    cout << "[B matrix]" << endl;
    print_matrix(mat_B, mat_B_row_size, mat_B_col_size);

    matrix_mul(mat_A, mat_A_row_size, mat_A_col_size, mat_B, mat_B_row_size,
               mat_B_col_size, scores);
    cout << "[Score matrix]" << endl;
    print_matrix(scores, mat_A_row_size, mat_B_col_size);

    return 0;
}
