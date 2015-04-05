/* 
 * Surrounded Regions
 * 
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 参考：
 * http://yucoding.blogspot.com/2013/08/leetcode-question-131-surrounded-regions.html
 */


class SurroundedRegions {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        
        // check if the alive surrounded region checked
        vector<vector<bool> > check (row, vector<bool>(col, false));
        
        // if current "O" has a way out, then put it into this queue, for BFS
        queue<pair<int, int> > bfsQ;
        
        for (int i=0; i<row; i++) {
            // search "O" from the first column
            if (board[i][0] == 'O') {
                bfsQ.push(make_pair(i, 0));
                check[i][0] = true;
            }
            
            // search "O" from the last column
            if (board[i][col-1] == 'O') {
                bfsQ.push(make_pair(i, col-1));
                check[i][col-1] = true;
            }
        }
        
        for (int i=0; i<col; i++) {
            // search "O" from the first row
            if (board[0][i] == 'O') {
                bfsQ.push(make_pair(0, i));
                check[0][i] = true;
            }
            
            // search "O" from the last row
            if (board[row-1][i] == 'O') {
                bfsQ.push(make_pair(row-1, i));
                check[row-1][i] = true;
            }
        }
        
        // BFS
        int i, j; // current position
        while (!bfsQ.empty()) {
            // get current position of live "O" from queue
            i = bfsQ.front().first;
            j = bfsQ.front().second;
            
            bfsQ.pop(); //pop up queue
            
            // search four directions of the current
            // NOTE: DO NOT check the boundary again
            // i-1 not 0, i+1 not row-1, j-1 not 0, j+1 not col-1
            
            // check the top
            if (i-1>0 && board[i-1][j]=='O' && check[i-1][j]==false) {
                bfsQ.push(make_pair(i-1, j));
                check[i-1][j] = true;
            }
            
            // check the bottom
            if (i+1<row-1 && board[i+1][j]=='O' && check[i+1][j]==false) {
                bfsQ.push(make_pair(i+1, j));
                check[i+1][j] = true;
            }
            
            // check the left
            if (j-1>0 && board[i][j-1]=='O' && check[i][j-1]==false) {
                bfsQ.push(make_pair(i, j-1));
                check[i][j-1] = true;
            }
            
            // check the right
            if (j+1<col-1 && board[i][j+1]=='O' && check[i][j+1]==false) {
                bfsQ.push(make_pair(i, j+1));
                check[i][j+1] = true;
            }
        }
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j]=='O' && check[i][j]==false)
                    board[i][j] = 'X';
            }
        }
    }
};