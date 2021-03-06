/* 
 * Dungeon Game
 * 
 * The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
 * The dungeon consists of M x N rooms laid out in a 2D grid.
 * Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
 * 
 * The knight has an initial health point represented by a positive integer.
 * If at any point his health point drops to 0 or below, he dies immediately.
 * 
 * Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
 * other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
 * 
 * In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
 * 
 * Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 * 
 * For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
 * 
 * -2 (K)	-3  	3
 * -5	   -10	    1
 * 10	    30     -5 (P)
 * 
 * Notes:
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
 * 
 * http://www.cnblogs.com/easonliu/p/4237644.html
 * 
 */


class DungeonGame {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
         int n = dungeon[0].size();
         //dp[i][j]表示进入这个格子后保证knight不会死所需要的最小HP。
         //如果一个格子的值为负，那么进入这个格子之前knight需要有的最小HP是-dungeon[i][j] + 1，方便起见这里先记为0-dungeon[i][j]，最后要加上1。
         //如果格子的值非负，那么最小HP需求就是1，这里先记为0，最后要加上1。
         //DP的方向是从最右下角开始一直到左上角。
         dungeon[m-1][n-1] = max(0-dungeon[m-1][n-1], 0);
         for (int i = m - 2; i >= 0; --i) {
             dungeon[i][n-1] = max(dungeon[i+1][n-1]-dungeon[i][n-1], 0);
         }
         for (int j = n - 2; j >= 0; --j) {
             dungeon[m-1][j] = max(dungeon[m-1][j+1]-dungeon[m-1][j], 0);
         }
         for (int i = m - 2; i >= 0; --i) {
             for (int j = n - 2; j >= 0; --j) {
                 dungeon[i][j] = max(min(dungeon[i][j+1], dungeon[i+1][j])-dungeon[i][j], 0);
             }
         }
         return dungeon[0][0] + 1;
    }
};