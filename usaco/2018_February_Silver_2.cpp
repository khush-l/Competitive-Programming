#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int num_tiles, num_boots;
    cin >> num_tiles >> num_boots;

    vector<int> tile_depths(num_tiles);
    vector<vector<int>> boots(num_boots);

    for(int i = 0; i < num_tiles; i++) {
        cin >> tile_depths[i];
    }

    for(int i = 0; i < num_boots; i++) {
        int max_depth, max_step;
        cin >> max_depth >> max_step;
        boots[i] = {max_depth, max_step};
    }

    // Initializing arrays to track the maximum amount of boots to move to each point
    vector<int> previous(num_tiles, -1), current(num_tiles, -1);
    previous[0] = 0; 
    current[0] = 0;

    // Looping through each boot
    for(int boot_idx = 0; boot_idx < num_boots; boot_idx++) {
        int max_depth = boots[boot_idx][0], max_step = boots[boot_idx][1];
        
        // Looping through each starting point
        for(int start = 0; start < num_tiles; start++) {
            if(previous[start] == -1 || tile_depths[start] > max_depth) continue;
            
            int current_step = 0;

            // Looping through adjacent tiles
            for(int j = 1; j < num_tiles - start && current_step < max_step; j++) {
                if(tile_depths[start + j] <= max_depth) {
                    current[start + j] = 1;
                    current_step = 0;
                } else {
                    current_step++;
                }
            }
        }
        
        // Updating the previous array
        previous = current;

        // Checking if the destination tile is reachable
        if(previous[num_tiles - 1] == 1) {
            cout << boot_idx << endl;
            break;
        }
    }

}
