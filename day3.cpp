#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {

        int tortoise = arr[0];
        int hare = arr[0];

        do {
            tortoise = arr[tortoise];
            hare = arr[arr[hare]];
        } while (tortoise != hare);

        tortoise = arr[0];
        while (tortoise != hare) {
            tortoise = arr[tortoise];
            hare = arr[hare];
        }

        return hare;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution s;
    int duplicate = s.findDuplicate(arr);
    cout << "Duplicate number is: " << duplicate << endl;

    return 0;
}