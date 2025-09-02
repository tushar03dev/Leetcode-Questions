class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currHeight =
                (i == n ? 0 : heights[i]); // flush the stack after completion
                                           // of all indices
                                           // n would be the nse of last stack element 

            while (!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
