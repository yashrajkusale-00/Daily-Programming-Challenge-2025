#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int total = m + n;

        int gap = (total + 1) / 2;

        while (gap > 0)
        {
            int i = 0, j = gap;
            while (j < total)
            {
                int a, b;

                if (i < n)
                    a = arr1[i];
                else
                    a = arr2[i - n];

                if (j < n)
                    b = arr1[j];
                else
                    b = arr2[j - n];

                if (a > b)
                {
                    if (i < n && j < n)
                    {
                        swap(arr1[i], arr1[j]);
                    }
                    else if (i < n && j >= n)
                    {
                        swap(arr1[i], arr2[j - n]);
                    }
                    else
                    {
                        swap(arr2[i - n], arr2[j - n]);
                    }
                }
                i++, j++;
            }
            if (gap == 1)
                break;
            gap = (gap + 1) / 2;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter size of arr1: ";
    cin >> n;
    cout << "Enter size of arr2: ";
    cin >> m;

    vector<int> arr1(n), arr2(m);

    cout << "Enter elements of arr1: ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cout << "Enter elements of arr2: ";
    for (int j = 0; j < m; j++)
        cin >> arr2[j];

    Solution s;
    s.merge(arr1, arr2);

    cout << "arr1 after merge: ";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    cout << "arr2 after merge: ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    return 0;
}
