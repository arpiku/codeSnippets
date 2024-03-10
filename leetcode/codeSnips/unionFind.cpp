
#include <vector>
#include <unordered_map>

class UnionFind {
private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> size;

public:
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            size[x] = 1;
        }

        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int maxSize() {
        int maxLength = 0;
        for (const auto &p : size) {
            maxLength = std::max(maxLength, p.second);
        }
        return maxLength;
    }
};

int longestConsecutive(std::vector<int>& nums) {
    UnionFind uf;
    for (int num : nums) {
        if (uf.find(num) == num) {  // Ensures only unique elements are considered
            if (uf.find(num - 1) != num - 1) {
                uf.unite(num, num - 1);
            }
            if (uf.find(num + 1) != num + 1) {
                uf.unite(num, num + 1);
            }
        }
    }
    return uf.maxSize();
}
