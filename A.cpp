#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

vector<vector<char>> board(N, vector<char>(N, '.'));
vector<bool> col(N, false), diag1(2*N-1, false), diag2(2*N-1, false);

bool solve(int y) {
    if (y == N) return true;
    
    for (int x = 0; x < N; x++) {
        if (board[y][x] == 'Q') {
            if (solve(y + 1)) return true;
            break;
        }
        if (!col[x] && !diag1[x+y] && !diag2[x-y+N-1]) {
            board[y][x] = 'Q';
            col[x] = diag1[x+y] = diag2[x-y+N-1] = true;
            
            if (solve(y + 1)) return true;
            
            board[y][x] = '.';
            col[x] = diag1[x+y] = diag2[x-y+N-1] = false;
        }
    }
    
    return false;
}

int main() {
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 'Q';
        col[c] = diag1[r+c] = diag2[c-r+N-1] = true;
    }
    
    solve(0);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
