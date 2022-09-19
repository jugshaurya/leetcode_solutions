class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int s = 0, e = n - 1;

        while(s < e) {
            int mid = (s + e) / 2;
            if(arr[mid + 1] > arr[mid]) s = mid + 1;
            else e = mid;
        }

        return s;
    }
};