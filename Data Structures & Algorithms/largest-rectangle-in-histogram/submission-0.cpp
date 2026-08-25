class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {

            while (!stack.empty() &&
                   heights[stack.top()] > heights[i]) {

                int height = heights[stack.top()];
                stack.pop();

                int width = stack.empty()
                    ? i
                    : i - stack.top() - 1;

                maxArea = std::max(
                    maxArea,
                    height * width
                );
            }

            stack.push(i);
        }

        // Alles, was noch im Stack ist,
        // konnte bis zum Ende des Arrays wachsen.
        int n = heights.size();

        while (!stack.empty()) {
            int height = heights[stack.top()];
            stack.pop();

            int width = stack.empty()
                ? n
                : n - stack.top() - 1;

            maxArea = std::max(
                maxArea,
                height * width
            );
        }

        return maxArea;
    }
};