#include"utils.h"
#include<queue>

int leastInterval_min(std::vector<char>& tasks, int n) {
    std::unordered_map<char,int> taskMap;
    int minCount = 0;

    for(auto& ch : tasks) {
        taskMap[ch]++;
    }

    while(!taskMap.empty()) {
    for(auto& pair:taskMap) {
        if(pair.second == 0) {
            taskMap.erase(pair.first);
        } else {
            pair.second--;
        }
    } minCount++;
    }
    return minCount;
}

int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    std::priority_queue<int> maxHeap;
    for (auto& pair : taskCount) {
        maxHeap.push(pair.second);
    }

    int intervals = 0;
    while (!maxHeap.empty()) {
        std::vector<int> cooldown;
        for (int i = 0; i <= n; i++) {
      LOG(i);
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                if (count > 1) {
                    cooldown.push_back(count - 1);
                }
            }
            intervals++;
            if (maxHeap.empty() && cooldown.empty()) {
                break;
            }
        }
        for (int count : cooldown) {
            maxHeap.push(count);
        }
    }

    return intervals;
}


int leastInterval_mine(std::vector<char>& tasks, int n) {
        std::unordered_map<char,int> taskCountMap;
        int intervals = 0;
        for(auto& task: tasks) {
            taskCountMap[task]++;
        }

        std::priority_queue<int> maxHeap;

  for(auto& pair: taskCountMap) { //Forgot this !! Do not from next time;
    maxHeap.push(pair.second);
  }

        while(!maxHeap.empty()) {
            std::vector<int> remaining;
        for (int i = 0; i <= n; i++) {
                if(!maxHeap.empty()) {
                    int toDoCount = maxHeap.top();
                    maxHeap.pop(); //Task getting done
                    if(toDoCount > 1) {
                    remaining.push_back(toDoCount);
                    }
                }
                intervals++;
                if(maxHeap.empty() && remaining.empty()) {
                    break;
                }
            }
            for(auto& taskCount:remaining) {
                maxHeap.push(taskCount);
            }
        }
        return intervals;
    }

int main() {
  std::vector<char> tasks = {'A','A','A','B','B','B'};
  std::cout << leastInterval(tasks,2);
  std::cout << leastInterval_mine(tasks,2);
  return 0;
}
