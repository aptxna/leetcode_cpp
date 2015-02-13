/**
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

class PascalTriangle {
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
