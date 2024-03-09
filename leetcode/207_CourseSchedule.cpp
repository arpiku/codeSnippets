class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> inDegree(numCourses, 0);
    for (const auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int prereq = prerequisite[1];
        graph[prereq].push_back(course);
        inDegree[course]++;
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        numCourses--;
        for (int dependentCourse : graph[course]) {
            if (--inDegree[dependentCourse] == 0) {
                q.push(dependentCourse);
            }
        }
    }
    return numCourses == 0;
}
};
