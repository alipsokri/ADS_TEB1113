#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<int> arr(m * n);

    cout << "Enter matrix elements:\n";

    // Input matrix into 1D array
    for (int i = 0; i < m * n; i++) {
        cin >> arr[i];
    }

    // Sort all elements
    sort(arr.begin(), arr.end());

    // Print back as matrix
    cout << "\nSorted Matrix:\n";

    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[index++] << " ";
        }
        cout << endl;
    }

    return 0;
}
