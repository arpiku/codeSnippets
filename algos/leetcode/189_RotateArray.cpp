//A nice solution 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k < nums.size())
            std::rotate(nums.rbegin(),nums.rbegin()+k,nums.rend());
        else
            rotate(nums, k-nums.size());
    }
};

// Implementation for std::rotate

template<class ForwardIt>
constexpr // since C++20
ForwardIt rotate(ForwardIt first, ForwardIt middle, ForwardIt last)
{
    if (first == middle)
        return last;
 
    if (middle == last)
        return first;
 
    ForwardIt write = first;
    ForwardIt next_read = first; // read position for when "read" hits "last"
 
    for (ForwardIt read = middle; read != last; ++write, ++read)
    {
        if (write == next_read)
            next_read = read; // track where "first" went
        std::iter_swap(write, read);
    }
 
    // rotate the remaining sequence into place
    rotate(write, next_read, last);
    return write;
}

// Full solution again

class Solution {

public:
    template<class rotateItr>
    constexpr
    rotateItr _rotate(rotateItr first, rotateItr middle, rotateItr last) {
        if(first == middle) 
            return last;
        if(middle == last)
            return first;
        
        rotateItr write = first;
        rotateItr readNext = first;

        for(rotateItr read = middle; read != last; ++write, ++read) {
            if(write == readNext)
                readNext = read;
            std::iter_swap(write,read);
        }
        _rotate(write,readNext,last);
        return write;
    }


    void rotate(vector<int>& nums, int k) {
        if (k < nums.size())
            _rotate(nums.rbegin(),nums.rbegin()+k,nums.rend());
        else
            rotate(nums, k-nums.size());
    }
};
