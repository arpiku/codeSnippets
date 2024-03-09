
#include <unordered_map>
#include <utility>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // XOR or combine hashes
    }
};

int main() {
    std::unordered_map<std::pair<int, int>, bool, pair_hash> m1;
    m1[std::make_pair(1, 2)] = true;
    m1[std::make_pair(3, 4)] = false;

    // Access the elements
    bool value1 = m1[std::make_pair(1, 2)];
    bool value2 = m1[std::make_pair(3, 4)];

    return 0;
}
