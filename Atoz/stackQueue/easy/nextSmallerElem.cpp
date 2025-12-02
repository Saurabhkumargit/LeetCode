// Next Smaller Element

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;  // stores indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return result;
    }
};
