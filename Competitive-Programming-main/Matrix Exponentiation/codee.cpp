#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<long long>> Matrix;

// Multiply two 2x2 matrices
Matrix matrixMultiplication(const Matrix &A, const Matrix &B) {
    Matrix result(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] =
                    (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return result;
}

// Matrix exponentiation using binary exponentiation
Matrix matrixExponentiation(const Matrix &base, int exponent) {
    if (exponent == 0) {
        return {{1, 0}, {0, 1}};
    }

    Matrix half = matrixExponentiation(base, exponent / 2);

    Matrix result = matrixMultiplication(half, half);

    if (exponent % 2 == 1) {
        result = matrixMultiplication(result, base);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    Matrix T = {
        {1, 1},
        {1, 0}
    };

    Matrix Tn = matrixExponentiation(T, n - 1);

    cout << Tn[0][0] << endl;

    return 0;
}