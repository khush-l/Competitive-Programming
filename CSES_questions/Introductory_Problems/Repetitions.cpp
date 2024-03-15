#include <iostream>
using namespace std;
#define ll long long

int main()
{
    string s; cin >> s;
    ll tot = 1;
    ll val = 1;
    for (ll i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i-1]) { 
            val++; 
            tot = max(tot, val); 
            }
        else {
            val = 1;
        }
    }
    cout << tot;
}