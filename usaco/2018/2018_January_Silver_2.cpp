#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int num_cows, num_stores, num_rentals;
    cin >> num_cows >> num_stores >> num_rentals;

    vector<int> cow_milk_production(num_cows);
    for (int &production : cow_milk_production) {
        cin >> production;
    }
    sort(cow_milk_production.rbegin(), cow_milk_production.rend());

    vector<pair<int, int>> stores(num_stores); // (price_per_gallon, available_gallons)
    for (auto &[gallons, price] : stores) {
        cin >> price >> gallons;
    }
    sort(stores.rbegin(), stores.rend());

    vector<ll> cow_profit(num_cows); // profit from cows
    for (int i = 0, j = 0; i < num_cows && j < num_stores;) {
        int bought_gallons = min(cow_milk_production[i], stores[j].second);
        cow_profit[i] += bought_gallons * stores[j].first;
        cow_milk_production[i] -= bought_gallons;
        stores[j].second -= bought_gallons;
        if (cow_milk_production[i] == 0) {
            i++;
        } else if (stores[j].second == 0) {
            j++;
        } else {
            assert(false);
        }
    }

    vector<int> rental_prices(num_rentals);
    for (int &price : rental_prices) {
        cin >> price;
    }

    // Calculate rental profits
    sort(rental_prices.rbegin(), rental_prices.rend());
    vector<ll> rental_profit;
    rental_profit.push_back(0);
    for (int i = 0; i < num_cows && i < num_rentals; ++i) {
        rental_profit.push_back(rental_profit.back() + rental_prices[i]);
    }
    rental_profit.resize(num_cows);
    reverse(rental_profit.begin(), rental_profit.end());

    // Prefix sum for total profits from cows
    vector<ll> total_cow_profit;
    total_cow_profit.push_back(0);
    for (ll &profit : cow_profit) {
        total_cow_profit.push_back(total_cow_profit.back() + profit);
    }

    ll max_profit = 0;
    for (int i = 0; i < num_cows; ++i) {
        max_profit = max(max_profit, total_cow_profit[i + 1] + rental_profit[i]);
    }

    cout << max_profit << '\n';
}
