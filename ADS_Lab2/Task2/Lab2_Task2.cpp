#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter matrix elements:\n";

    //Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nMatrix after 180 degree rotation:\n";

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}