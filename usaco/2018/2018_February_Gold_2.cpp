#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compareRestStops(const pair<ll,ll>& a, const pair<ll,ll>& b){
    // Custom comparison function for sorting rest stops based on tastiness and distance
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second; 
}

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

	ll totalDistance, numRestStops, farmerSpeed, bessieSpeed;
	cin >> totalDistance >> numRestStops >> farmerSpeed >> bessieSpeed;

	vector<pair<ll,ll>> restStops(numRestStops); // Stores tastiness and distance of rest stops
	for(ll i = 0; i < numRestStops;  i++){
		cin >> restStops[i].first >> restStops[i].second; // Reading tastiness and distance of each rest stop
	}

	sort(restStops.begin(), restStops.end(), compareRestStops); // Sorting rest stops

	ll totalTastiness = 0, lastStopBessie = 0, currentPos = 0;
	for(ll i = 0 ; i < numRestStops; i++){

		if(restStops[i].first < currentPos) continue; // If Bessie passes this stop, skip

		ll reachBessie = bessieSpeed * restStops[i].first + lastStopBessie; // Time taken for Bessie to reach
		ll reachFarmer = farmerSpeed * restStops[i].first; // Time taken for Farmer to reach

		// Add tastiness gained at this stop
		totalTastiness += (reachFarmer - reachBessie) * restStops[i].second;
		currentPos = restStops[i].first; 

		lastStopBessie += (reachFarmer - reachBessie); // Update last stop for Bessie

	}
	cout << totalTastiness; 
}
