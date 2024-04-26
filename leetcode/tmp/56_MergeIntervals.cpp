#include "utils.h"


vec2dInt merge(vec2dInt& intervals) { 
	vec2dInt res;
	std::sort(intervals.begin(),intervals.end());

	for(auto& interval: intervals) {
		int start = interval.front();
		int end = interval.back();
		if(!res.empty() && res.back()[1] >= start) {
			res.back()[1] = std::max(end,res.back()[1]);
		} else {
			res.push_back(interval);
		}
	}
	return res;
}
	
	


int main() {
	vec2dInt vv = {{1,3},{2,6},{8,10},{15,18}};
	vec2dInt vv2 = {{1,4},{4,5}};
	vv = merge(vv);
	vv2 = merge(vv2);
	printVec(vv);
	printVec(vv2);

	return 0;
}
