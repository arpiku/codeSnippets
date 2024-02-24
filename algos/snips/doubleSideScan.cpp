class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> rightProduct(1,1);
        std::vector<int> leftProduct(1,1);
        std::vector<int> productArr(nums.size(),1);

        auto frontItr = nums.begin()+1;
        auto backItr = nums.rbegin()+1;

        int rP = 1;
        int lP = 1;

        std::cout << *(backItr-1) << std::endl;

        while(frontItr != nums.end()) {
            int temp =  *(frontItr-1);
            lP *= temp;
            leftProduct.push_back(lP);
            frontItr++;
        }

        while(backItr != nums.rend()) {
            int temp =  *(backItr-1);
            rP *= temp;
            rightProduct.push_back(rP);
            backItr++;
        }

        for(auto& i:leftProduct) 
            std::cout << i << ", ";
        

        std::cout << "---" << std::endl;
        for(auto& i:rightProduct) 
            std::cout << i << ", ";
        return {};
    }
};
