#include "utils.h"

int trap(std::vector<int> heights) {
  int n = heights.size();
  if(n <= 2)
    return 0;

  std::stack<int> stk;
  int water = 0; //No water :(

  //Let's get some

  for(int i = 0; i<n; i++) {
    while(!stk.empty() && heights[i] > heights[stk.top()]) {
      int topIdx = stk.top();
      stk.pop();
      if(!stk.empty()) {
        int distance = i - stk.top() - 1;
        int boundedHeight = std::min(heights[i], heights[stk.top()] - heights[topIdx]);
        water += distance*boundedHeight;
      }int trapRainWater(const vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) return 0;  // Cannot trap water with less than 3 bars
    
    stack<int> st;  // Stack to store indices of bars
    int water = 0;
    
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] > heights[st.top()]) {
            int topIdx = st.top();
            st.pop();
            if (!st.empty()) {
                int distance = i - st.top() - 1;
                int boundedHeight = min(heights[i], heights[st.top()]) - heights[topIdx];
                water += distance * boundedHeight;
            }
        }
        st.push(i);
    }
    
    return water;
}
    } 
  }
  return water;

}

int main() {
  std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
  int water = trap(heights);
  LOG(water);
  return 0;
}
