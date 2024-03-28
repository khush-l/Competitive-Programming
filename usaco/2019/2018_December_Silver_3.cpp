#include <bits/stdc++.h>
using namespace std;

int rows, k;
int blocks[100][10];
bool visited[100][10];
//check if adjacent blocks have the same value
int check(int x, int y, int val) {
    int count = 0;
    if (x < 0 || x >= rows || y < 0 || y >= 10 || visited[x][y]) {
        return 0;
    }
    if (blocks[x][y] == val) {
        visited[x][y] = true;
        count++;
        count += check(x - 1, y, val);
        count += check(x + 1, y, val);
        count += check(x, y - 1, val);
        count += check(x, y + 1, val);
    }
    return count;
}

//apply gravity and move blocks downwards
void applyGravity() {
    for (int col = 0; col < 10; col++) {
        int nextRow = rows - 1;
        for (int currentRow = rows - 1; currentRow >= 0; currentRow--) {
            visited[currentRow][col] = false;
            if (blocks[currentRow][col] != 0) {
                int temp = blocks[currentRow][col];
                blocks[currentRow][col] = 0;
                blocks[nextRow][col] = temp;
                nextRow--;
            }
        }
    }
}

//clear connected blocks of the same value
void clearBlocks(int x, int y, int val) {
    if (x < 0 || x >= rows || y < 0 || y >= 10) {
        return;
    }
    if (blocks[x][y] == val) {
        blocks[x][y] = 0;
        clearBlocks(x - 1, y, val);
        clearBlocks(x + 1, y, val);
        clearBlocks(x, y - 1, val);
        clearBlocks(x, y + 1, val);
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> rows >> k;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 10; j++) {
            char blockChar;
            cin >> blockChar;
            blocks[i][j] = blockChar - '0';
        }
    }
    bool finished = false;
    while (!finished) {
        finished = true;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 10; j++) {
                if (blocks[i][j] != 0 && !visited[i][j] && check(i, j, blocks[i][j]) >= k) {
                    finished = false;
                    clearBlocks(i, j, blocks[i][j]);
                }
            }
        }
        if (!finished) {
            applyGravity();
        }
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 10; c++) {
            cout << blocks[r][c];
        }
        cout << "\n";
    }
}
