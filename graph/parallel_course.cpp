#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parallelCourses(int n, vector<vector<int>>& prerequisites) {

    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (auto& edge : prerequisites) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        indegree[v]++;
    }

    // pair = {course, semester}
    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {

        if (indegree[i] == 0) {
            q.push({i, 1});
        }
    }

    int completedCourses = 0;
    int answer = 0;

    while (!q.empty()) {

        auto pair = q.front();

        int course = pair.first ;
        int semester = pair.second ;
        q.pop();

        completedCourses++;

        // Maximum semester required
        answer = max(answer, semester);

        // Process courses depending on current course
        for (int nextCourse : adj[course]) {

            indegree[nextCourse]--;

            // All prerequisites completed
            if (indegree[nextCourse] == 0) {

                q.push({nextCourse, semester + 1});
            }
        }
    }

    // Cycle detection
    if (completedCourses != n) {
        return -1;
    }

    return answer;
}


int main() {

    int n;
    int m;

    cout << "Enter number of courses: ";
    cin >> n;

    cout << "Enter number of prerequisites: ";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));

    cout << "Enter prerequisites (u v), where u must be completed before v:\n";

    for (int i = 0; i < m; i++) {

        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    int result = parallelCourses(n, prerequisites);

    cout << "Minimum number of semesters: " << result << endl;

    return 0;
}