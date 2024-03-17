#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vals(n);
    for (auto &x : vals)
        cin >> x;

    map<int, int> nums;
    int tot = 0;

    for (int i = 0, j = 0; j < n; ++j)
    {
        while (nums[vals[j]] > 0)
            nums[vals[i++]]--;
        nums[vals[j]]++;
        tot = max(tot, j - i + 1);
    }

    cout << tot << '\n';
}
