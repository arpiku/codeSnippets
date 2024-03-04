class Solution {
public:
    int maxArea(vector<int>& height) {

        size_t area = 0;

        for(int leftWall = 0; leftWall<height.size(); leftWall++) {
            for(int rightWall = leftWall+1; rightWall<height.size(); rightWall++) {
                size_t temp = std::min(height[leftWall],height[rightWall])*(rightWall-leftWall);
                area = std::max(temp,area);
            }
        }
        return area;
        
    }
}; //This solution exceeds time limit, the better idea would be to use two pointers to handle this situation.
   //

// But the following works
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2)
            return INT_MIN;
        int area = INT_MIN;
        int rightWall = height.size()-1;
        int leftWall = 0;
        while(leftWall < rightWall) {
            int currHeight = std::min(height[leftWall],height[rightWall]);
            int currArea = currHeight*(rightWall-leftWall);

            if(height[leftWall] < height[rightWall])
                leftWall++;
            else
                rightWall--;

            area = std::max(currArea,area);

        }
        return area;
        
    }
};
