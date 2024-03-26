#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 250;

int grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// Floodfill algorithm to find the size of a region with colors color1 and color2
int floodfill(int size, int row, int col, int color1, int color2, int sizeLimit) {
    // Base cases for termination of recursion
    if(row < 0 || row >= n || col < 0 || col >= n || (grid[row][col] != color1 && grid[row][col] != color2) || visited[row][col]) {
        return size;
    }
    visited[row][col] = true;
    size++;
    
    // Recursively call floodfill in four directions
    size = floodfill(size, row, col + 1, color1, color2, sizeLimit);
    size = floodfill(size, row, col - 1, color1, color2, sizeLimit);
    size = floodfill(size, row - 1, col, color1, color2, sizeLimit);
    size = floodfill(size, row + 1, col, color1, color2, sizeLimit);
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    
    int n;
    cin >> n;

    // Reading the grid
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0; 

    // Finding the largest individual region
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j], n*n)); // Note: color1 and color2 are the same
            }
        }
    }
    cout << ans << '\n';

    ans = 0; 

    // Finding the largest team region (adjacent y IDs)
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(ans >= n*n/2) {
                cout << ans << '\n'; // Output if the region is already large enough
                return 0;
            }
            if(grid[i][j] != grid[i][j-1]) {
                memset(visited, 0, sizeof(visited));
                ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j-1], n*n)); // Finding the size of the team region
            }
        }
    }

    // Finding the largest team region (adjacent x IDs)
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans >= n*n/2) {
                cout << ans << '\n'; 
                return 0;
            }
            if(grid[i][j] != grid[i-1][j]) {
                memset(visited, 0, sizeof(visited)); // Resetting visited array
                ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i-1][j], n*n)); // Finding the size of the team region
            }
        }
    }
    cout << ans << '\n'; 
    return 0;
}
