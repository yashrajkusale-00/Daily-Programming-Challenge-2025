#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>& arr) {
    int n = arr.size() + 1 ;             
    int total_sum = (n - 1) * n / 2;      
    int array_sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        array_sum += arr[i];              
    }

    return total_sum - array_sum;         
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter numbers from : " << endl; ;
    for (int i = 0; i < size - 1; i++) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr);
    cout << "The missing number is: " << missing << endl;

    return 0;
}
