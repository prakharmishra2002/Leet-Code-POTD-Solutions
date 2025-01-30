class Solution {
public:
    // Main function to calculate the maximum number of magnificent sets
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            // Transition to 0-index
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            // Start coloring from uncolored nodes
            colors[node] = 0;
            // If the graph is not bipartite, return -1
            if (!isBipartite(adjList, node, colors)) return -1;
        }

        // Calculate the longest shortest path for each node
        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            // Add the number of groups for this component to the total
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList, node, distances, visited);
        }

        return maxNumberOfGroups;
    }

private:
    // Checks if the graph is bipartite starting from the given node
    bool isBipartite(vector<vector<int>> &adjList, int node,
                     vector<int> &colors) {
        for (int neighbor : adjList[node]) {
            // If a neighbor has the same color as the current node, the graph
            // is not bipartite
            if (colors[neighbor] == colors[node]) return false;

            // If the neighbor is already colored, skip it
            if (colors[neighbor] != -1) continue;

            // Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2;

            // Recursively check bipartiteness for the neighbor; return false if
            // it fails
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        // If all neighbors are properly colored, return true
        return true;
    }

    // Computes the longest shortest path (height) in the graph starting from
    // the source node
    int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode,
                               int n) {
        // Initialize a queue for BFS and a visited array
        queue<int> nodesQueue;
        vector<bool> visited(n, false);

        nodesQueue.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        // Perform BFS layer by layer
        while (!nodesQueue.empty()) {
            // Process all nodes in the current layer
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();

                // Visit all unvisited neighbors of the current node
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
            // Increment the distance for each layer
            distance++;
        }
        // Return the total distance (longest shortest path)
        return distance;
    }

    // Calculates the maximum number of groups for a connected component
    int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node,
                                      vector<int> &distances,
                                      vector<bool> &visited) {
        // Start with the distance of the current node as the maximum
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        // Recursively calculate the maximum for all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};
