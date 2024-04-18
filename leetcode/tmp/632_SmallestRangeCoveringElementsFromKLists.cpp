#include"utils.h"


// [a,b]
// a = std::max(a, nums.begin());
// b = std::min(b, num.rbegin());

struct Element {
    int value;
    int listIndex;
    int elementIndex;
    
    Element(int val, int li, int ei) : value(val), listIndex(li), elementIndex(ei) {}

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

std::pair<int, int> smallestRange(std::vector<std::vector<int>>& nums) {

    int k = nums.size();
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;

    int maxVal = std::numeric_limits<int>::min();
    for (int i = 0; i < k; i++) {
        minHeap.emplace(nums[i][0], i, 0);
        maxVal = std::max(maxVal, nums[i][0]);
    }

    int rangeStart = -1;
    int rangeEnd = -1;
    int minRange = std::numeric_limits<int>::max();

    while (true) {
        Element curr = minHeap.top();
        minHeap.pop();

        int currRange = maxVal - curr.value;
        if (currRange < minRange) {
            minRange = currRange;
            rangeStart = curr.value;
            rangeEnd = maxVal;
        }

        if (curr.elementIndex == nums[curr.listIndex].size() - 1) {
            break; // Reached end of any list
        }

        int nextVal = nums[curr.listIndex][curr.elementIndex + 1];
        maxVal = std::max(maxVal, nextVal);
        minHeap.emplace(nextVal, curr.listIndex, curr.elementIndex + 1);
    }

    return {rangeStart, rangeEnd};
}

