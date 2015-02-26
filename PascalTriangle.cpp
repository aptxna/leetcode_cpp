/**
 * Pascal's Triangle II
 * Given an index k, return the Kth row of the Pascal's triangle.
 * Fro example, given k=3,
 * Return [1,3,3,1].
 * 
 * Consider like this:
 * 0 1 0 0 0
 * 0 1 1 0 0
 * 0 1 2 1 0
 * 0 1 3 3 1
 * ...
 * and add from back to front.
 */

class PascalTriangleII {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> pt;
		pt.resize(rowIndex+2);
		for (int i=0; i<rowIndex+2; i++) {
			pt[i]=0;
		}
		pt[1]=1;
		for (int i=0; i<rowIndex; i++) {
			for (int j=rowIndex+1; j>0; j--) {
				pt[j]=pt[j-1]+pt[j];
			}
		}
		pt.erase(pt.begin()); //erase the first "0"
		return pt;
	}
};


/**
 * Pascal's Triangle
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return:
 * [
 *      [1]
 *     [1,1]
 *    [1,2,1]
 *   [1,3,3,1]
 *  [1,4,6,4,1]
 * ]
 */

class PascalTriangle {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows<=0) return res;
		for (int i=0; i<numRows; i++) {
			vector<int> vec;
			vec.clear();
			vec.push_back(1);
			for (int j=1; j<=i; j++) {
				vec.push_back(res[i-1][j-1]+(j<i?res[i-1][j]:0));
			}
			res.push_back(vec);
		}
		return res;
	}
};
