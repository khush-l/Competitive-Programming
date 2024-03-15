#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

const int MAX_N = 16;

int main()
{
    int N;
    cin >> N;

    bool binary[MAX_N + 1];

    for (int i = 1; i <= N; ++i)
        binary[i] = false;

    for (int i = 1; i <= (1 << N); ++i)
    {
        for (int j = N; j > 0; --j)
            cout << binary[j];
        
        cout << '\n';

        int LSB = __builtin_ffs(i);
        binary[LSB] ^= 1;
    }

    return 0;
}