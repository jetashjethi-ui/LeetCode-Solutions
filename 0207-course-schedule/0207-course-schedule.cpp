#include <vector>
using namespace std;

class Solution {
public:
    bool hasCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path) {
        visited[node] = true;
        path[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, adj, visited, path)) {
                    return true; // Cycle detected in sub-path
                }
            } else if (path[neighbor]) {
                return true; // Back-edge found -> Cycle detected
            }
        }

        path[node] = false; // Backtrack: leave path stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph using pair[0] -> pair[1]
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycleDFS(i, adj, visited, path)) {
                    return false; // Cycle exists -> cannot finish
                }
            }
        }

        return true; // No cycle exists -> can finish all courses
    }
};