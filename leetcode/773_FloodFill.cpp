//This code does not work!, Do not use it

```cpp
class Solution {
public:
    typedef std::pair<int,int> direction;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       // if(sr >= image.size() || image.at(0).size() <= sc || 0 > sr || sc < 0) return image;
        auto lookAt = [&] (direction m){return image.at(m.first).at(m.second);};
        auto moveAndColor = [&](direction m, int clr){return floodFill(image, sr + m.first, sc + m.second, clr);};

        const int colorValue = image.at(sr).at(sc);

        image[sr][sc] = color;

        const std::vector<direction> directions = {{0,-1},{0,1},{1,0},{-1,0}};
        for_each(directions.begin(),directions.end(), [&](direction direct){
            try {
                int clr = lookAt(direct);
                if(clr == colorValue)
                    return moveAndColor(direct,color);

            } catch (const std::out_of_range& e) {
                std::cout << "too far" << std::endl;
            } return image;
        });
        return image;
        
    }
};

```

