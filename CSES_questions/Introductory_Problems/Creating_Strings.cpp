#define ll long long
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    vector<string> tot;
    do
    {
        tot.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << tot.size() << '\n';
    for (auto &x : tot)
        cout << x << '\n';
}