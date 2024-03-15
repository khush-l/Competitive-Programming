#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    ll tot = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            tot += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }

    cout << tot;
}






