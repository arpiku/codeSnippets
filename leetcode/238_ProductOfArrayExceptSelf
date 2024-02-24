class Solution {

template<class Itr>
std::vector<int> shiftedProduct(Itr first, Itr last) {
    std::vector<int> res(1,1);
    int p = 1;
    while(first != last) {
        int t = *(first - 1);
        p *= t;
        res.push_back(p);
        first++;
    }
    return res;
}
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> productArr(nums.size(),1);
        std::vector<int> rightProduct = shiftedProduct(nums.begin()+1,nums.end());
        std::vector<int> leftProduct = shiftedProduct(nums.rbegin()+1,nums.rend());
        std::transform(rightProduct.begin(),rightProduct.end(),leftProduct.rbegin(),productArr.begin(),[](int a, int b){return a*b;});


return productArr;   
 }
};
