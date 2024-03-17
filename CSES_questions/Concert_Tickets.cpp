#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int, greater<int>> vals;
    while (n--)
    {
        int i;
        cin >> i;
        vals.insert(i);
    }

    while (m--)
    {
        int i;
        cin >> i;

        auto it = vals.lower_bound(i);
        if (it == vals.end())
            cout << "-1\n";
        else
        {
            cout << *it << '\n';
            vals.erase(it);
        }
    }
}
