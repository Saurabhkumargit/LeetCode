// Job sequencing Problem

class Solution {
  public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        sort(Jobs.begin(), Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        int n = Jobs.size();
        int maxDeadline = 0;
        for (auto &job : Jobs) maxDeadline = max(maxDeadline, job[1]);

        vector<bool> slot(maxDeadline + 1, false);

        int countJobs = 0;
        int maxProfit = 0;

        for (auto &job : Jobs) {
            int deadline = job[1];
            int profit = job[2];

            for (int t = deadline; t >= 1; t--) {
                if (!slot[t]) {
                    slot[t] = true;
                    countJobs++;
                    maxProfit += profit;
                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};
