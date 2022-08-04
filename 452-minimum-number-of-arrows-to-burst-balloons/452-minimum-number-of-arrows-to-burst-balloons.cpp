// sorting by x-end
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int>& pointA, vector<int>& pointB){
           return pointA[1] < pointB[1]; 
        });
        
        int arrows = 1;
        int lastShoot = points[0][1];
        int n = points.size();
        
        for(int i=1; i<n; i++) {
            if(lastShoot < points[i][0]){
                arrows++;
                lastShoot = points[i][1];
            }
        }
        
        return arrows;
    }
};

// sorting by x-start
// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         sort(points.begin(), points.end(), [&](vector<int> &pointA, vector<int> &pointB){
//             if(pointA[0] == pointB[0]) return pointA[1] < pointB[1];
//             return pointA[0] < pointB[0]; 
//         });
        
//         int arrows = 1;
//         int lastShoot = points[0][1];
//         int n = points.size();
//         for(int i = 1; i < n; i++) {
//             if(lastShoot < points[i][0]){
//                 arrows++;
//                 lastShoot = points[i][1];
//             }
//             if(lastShoot > points[i][1]){
//                 lastShoot = points[i][1];
//             }
//         }
        
//         return arrows;
//     }
// };

// // 
// // [[1,10] [3,9] [4,11] [6,7] [6,9] [8,12] [9,12]]










