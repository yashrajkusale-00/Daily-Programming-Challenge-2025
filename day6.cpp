#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSubarrays = n * (n + 1) / 2;
    vector<int> startIndex(maxSubarrays);
    vector<int> endIndex(maxSubarrays);
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                startIndex[count] = i;
                endIndex[count] = j;
                count++;
            }
        }
    }

    cout << "[";
    for (int k = 0; k < count; k++) {
        cout << "(" << startIndex[k] << ", " << endIndex[k] << ")";
        if (k != count - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
