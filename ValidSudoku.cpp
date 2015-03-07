/**
 * Valid Sudoku
 * Determine if a Sudoku is valid, according to:
 * Sudoku Puzzles - The Rules
 * http://sudoku.com.au/TheRules.aspx
 * The Sudoku board could be partially filled
 * where empty cells are filled with the character '.'
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 *
 * Hint: Hash Table
 */

 class ValidSudoku {
 public:
 	bool isValidSudoku(vector<vector<char> > &board) {
 		if (board.size() == 0)
 			return false;

 		//定义一个向量用来存每行的Hash值
 		int row[9] = {0};
 		//定义一个向量用来存每列的Hash值
 		int col[9] = {0};

 		for (int i=0; i<9; i++) {
 			//这两个向量可按行列重复使用，每次使用前需清零
 			memset(row, 0, 9*sizeof(int));
 			memset(col, 0, 9*sizeof(int));

 			for (int j=0; j<9; j++) {
 				//按行判断
 				if (board[i][j] != '.') {
 					//board[i][j]-49先将字符转整型，49是字符'1'的ASCII码
 					//转为整型之后对应row向量的下标0～8，这里是个Hash表
 					//判断向量值是否为“1”，是则说明该数字已出现过一次，返回false
 					//否则将该向量值置为“1”
 					if (row[board[i][j]-49] == 1)
 						return false;
 					row[board[i][j]-49]++;
 				}

 				//按列判断
 				if (board[j][i] != '.') {
 					if (col[board[j][i]-49] == 1)
 						return false;
 					col[board[j][i]-49]++;
 				}
 			}
 		}

 		//这里是对三行三列9个小九宫格判断
 		//m+i，n+j分别对应原大九宫格的行列坐标
 		for (int i=0; i<9; i+=3) {
 			for (int j=0; j<9; j+=3) {
 				//这里的row向量存储每一个小九宫格9个元素的hash值，
 				//循环使用9次，每次循环前需清零
 				memset(row, 0, 9*sizeof(int));

 				for (int m=0; m<3; m++) {
 					for (int n=0; n<3; n++) {
 						if (board[m+i][n+j] == '.')
 							continue;
 						if (row[board[m+i][n+j]-49] == 1)
 							return false;
 						row[board[m+i][n+j]-49]++;
 					}
 				}
 			}
 		}

 		return true;
 	}
 };