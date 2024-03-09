class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m;
        std::vector<int> ws;
        std::vector<int> res;
        int i = 0;
        for(auto& w:words) {
            if(m.find(w) != m.end()) {
                ws.push_back(m[w]);
                continue;
            }         
            m[w] = i++;
            ws.push_back(m[w]);
        }
        std::sort(ws.begin(),ws.end());

        int L = words.size()* words[0].size();
        int l = words[0].size();
        int j = 0;

        while(j < s.size()) {
            std::vector<int> splits;
            std::string temp = s.substr(j,std::min(L,int(s.size()-j)));
            for(int k = 0; k < temp.size(); k+=l) {
                std::string currS = temp.substr(k,std::min(l,int(temp.size()-k)));
                if(m.find(currS) == m.end())
                    break;
                else
                    splits.push_back(m[currS]);
            }
            if(splits.size() == ws.size()) {
                std::sort(splits.begin(),splits.end());
                if(splits == ws)
                    res.push_back(j);
            }  
            j++;          
        }
        return res;
        
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};

        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            ++wordCount[word]; 
        }

        vector<int> indices;
        int wordLength = words[0].size();
        int windowLength = wordLength * words.size();
        int n = s.size();

        for (int i = 0; i < wordLength; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seenWords;

            for (int right = i; right <= n - wordLength; right += wordLength) {
                string word = s.substr(right, wordLength);
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;

                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    if (count == words.size()) {
                        indices.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }

        return indices;
    }
};
