/**
 * Max Points on a Line
 * 
 * Given n points on a 2D plane, find the maximum number of points
 * that lie on the same straight line.
 * 
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class MaxPointsOnaLine {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float, int> slope; //记录直线斜率的hash map, float记录斜率，int记录与当前点同线的点的个数
        int maxNum = 0; //记录同一条直线的点数的最大值
        //扫描points中所有的点
        for (int i=0; i<points.size(); i++) {
            slope.clear(); //slope初始化
            int duplicate = 1; //记录坐标相同的点数，初始化为1，即为当前点
            //对第二个点进行扫描，求斜率
            for (int j=0; j<points.size(); j++) {
                if (j == i)
                    continue; //跳过当前点以免重复扫描该点
                if (points[j].y == points[i].y && points[j].x == points[i].x) {
                    duplicate++; //如果坐标与当前点相同则记录为重复点，也算共线
                    continue;
                }
                //计算两不相同的点所在直线的斜率，若垂直则记为INT_MAX
                float k = (points[j].x - points[i].x) == 0 ? INT_MAX : 
                            (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);
                slope[k]++;
            }
            //若slope为空的情况，points中只有一个点或者所有点的坐标相同，此时maxNum应为duplicate值
            if (slope.size() == 0)
                maxNum = duplicate;
            else {
            	//遍历hash map求maxNum
                for (auto& x: slope) {
                    if (x.second + duplicate > maxNum)
                        maxNum = x.second + duplicate;
                }
            }
        }
        //返回同在一条直线上的点数的最大值
        return maxNum;
    }
};