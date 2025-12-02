// Number of Greater Elements to the Right

class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();

        // --- Step 1: Coordinate Compression ---
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        auto getID = [&](int x) {
            return lower_bound(sortedArr.begin(), sortedArr.end(), x) - sortedArr.begin() + 1;
        };

        int m = sortedArr.size();
        vector<int> fenwick(m + 1, 0);

        auto update = [&](int i, int val) {
            while (i <= m) {
                fenwick[i] += val;
                i += (i & -i);
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += fenwick[i];
                i -= (i & -i);
            }
            return sum;
        };

        vector<int> greaterCount(n, 0);

        // --- Step 2: Traverse from right to left ---
        for (int i = n - 1; i >= 0; i--) {
            int id = getID(arr[i]);
            // Count values strictly greater → query total - query(id)
            greaterCount[i] = query(m) - query(id);
            update(id, 1); // Insert this value
        }

        // --- Step 3: Build results for queries ---
        vector<int> result;
        result.reserve(indices.size());
        for (int idx : indices)
            result.push_back(greaterCount[idx]);

        return result;
    }
};
