#define INF 1e9
class Solution {
  public:
  int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    int mini = INF;
    for (int i = 0; i <= 99; i++) {
      for (int j = 0; j <= 99; j++) {
        if (i * 60 + j == targetSeconds) {
          int temp[4] = {i / 10, i % 10, j / 10, j % 10};
          int ptr = 0;
          while (temp[ptr] == 0) ptr++;
          int totalButtonToPush = 4 - ptr;

          int tmp = startAt;
          int totalMoves = 0;
          while (ptr < 4) {
            if (tmp != temp[ptr]) {
              totalMoves++;
              tmp = temp[ptr];
            }
            ptr++;
          }

          mini = min(mini, totalMoves * moveCost + totalButtonToPush * pushCost);
        }
      }
    }
    return mini;
  }
};
