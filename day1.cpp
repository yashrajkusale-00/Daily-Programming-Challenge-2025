#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else { 
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        if (n == 0) {
            throw runtime_error("Error: Empty array is not allowed.");
        }

        vector<int> nums(n);
        cout << "Enter elements (only 0, 1, or 2): ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] != 0 && nums[i] != 1 && nums[i] != 2) {
                throw invalid_argument("Error: Only 0, 1, or 2 are allowed.");
            }
        }

        if (isSorted(nums)) {
            throw logic_error("Notice: The array is already sorted.");
        }

        sort(nums);

        cout << "Sorted array: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;

    } 
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } 
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    catch (const logic_error& e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "An unknown error occurred." << endl;
    }
    return 0;
}
