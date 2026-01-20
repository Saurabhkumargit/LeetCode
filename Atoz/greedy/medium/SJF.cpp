// Shortest Job First

class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        sort (bt.begin(), bt.end());

        long long waitSum = 0;
        long long prefix = 0;

        for (int i = 0; i < (int)bt.size(); i++) {
          waitSum += prefix;
          prefix += bt[i];
        }
        return waitSum/bt.size();
    }
};