#include"utils.h"

struct Person  {
	std::string name;
	std::set<std::string> emails;

	Person(std::string name, std::set<std::string> emails) : name(name), emails(emails) {}

	bool hasCommonMail(const std::set<std::string>& set1, const std::set<std::string>& set2) const  {
    std::set<std::string> intersectionSet;

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(intersectionSet, intersectionSet.begin()));

    return !intersectionSet.empty();
}

	bool operator==(const Person& other)const { 
		return (name == other.name) && hasCommonMail(emails, other.emails);
	}

	void addEmails(const std::set<std::string> newEmails) {
		emails.insert(newEmails.begin(),newEmails.end());
	}
	
	
};

std::vector<std::vector<std::string>> accountsMerge_not_work(std::vector<std::vector<std::string>>& accounts) { // This code doesn't wor
	std::sort(accounts.begin(),accounts.end());
	std::vector<Person> accs;
	LOG(accs.size());
	for(auto& acc:accounts) {
		LOG("size of accs");
		LOG(accs.size());
		std::string name = acc.at(0);
		std::set<std::string> emails(acc.begin()+1,acc.end());			
		Person currPerson = Person(name,emails);

		
		auto itr = std::find(accs.begin(),accs.end(),currPerson);

		if(itr == accs.end()) {
			accs.push_back(currPerson);
			continue;
	} 
		LOG((itr != accs.end()))
		itr->addEmails(currPerson.emails);

	}

	std::vector<std::vector<std::string>> res;
	std::cout << accs.size() << std::endl;
	for(auto& acc:accs) {
	std::vector<std::string> temp;
		temp.push_back(acc.name);
		temp.insert(temp.end(),acc.emails.begin(),acc.emails.end());
		res.push_back(temp);
	}

return res;  
}

class UnionFind {
private:
    std::vector<int> parents;

public:
    UnionFind(int N) : parents(N) {
        std::iota(parents.begin(), parents.end(), 0); 
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unite(int child, int parent) {
        parents[find(child)] = find(parent);
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
        int N = accounts.size();
        UnionFind uf(N);

        std::unordered_map<std::string, int> ownership;
        for (int i = 0; i < N; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                const std::string& email = accounts[i][j];
                if (ownership.count(email)) {
                    uf.unite(i, ownership[email]);
                }
                ownership[email] = i;
            }
        }

        std::unordered_map<int, std::vector<std::string>> mergedAccounts;
        for (const auto& [email, owner] : ownership) {
            int root = uf.find(owner);
            mergedAccounts[root].push_back(email);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& [root, emails] : mergedAccounts) {
            std::vector<std::string> merged = { accounts[root][0] };
            merged.insert(merged.end(), emails.begin(), emails.end());
            std::sort(merged.begin() + 1, merged.end());
            result.push_back(merged);
        }

        return result;
    }
};

int main() {
std::vector<std::vector<std::string>> accounts = {
{"David","David0@m.co","David1@m.co"},
{"David","David3@m.co","David4@m.co"},
{"David","David4@m.co","David5@m.co"},
{"David","David2@m.co","David3@m.co"},
{"David","David1@m.co","David2@m.co"}};
	Solution s;
	s.accountsMerge(accounts);
	return 0;
}
