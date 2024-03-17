#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> vals;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        vals.insert(x);
    }

    cout << vals.size();
}