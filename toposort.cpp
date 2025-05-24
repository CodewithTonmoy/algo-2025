#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(unordered_map<string, vector<string>>& graph) {
    unordered_map<string, int> inDegree;
 
    for (auto& pair : graph) {
        const string& node = pair.first;
        if (inDegree.find(node) == inDegree.end()) {
            inDegree[node] = 0;
        }
        for (const string& neighbor : pair.second) {
            inDegree[neighbor]++;
        }
    }

  
    queue<string> q;
    for (auto& pair : inDegree) {
        if (pair.second == 0) {
            q.push(pair.first);
        }
    }

    vector<string> topoOrder;

    while (!q.empty()) {
        string node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (const string& neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }


    if (topoOrder.size() != inDegree.size()) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return;
    }


    cout << "Topological Order: ";
    for (const string& node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
 
    unordered_map<string, vector<string>> graph;
    graph["A"] = {"C"};
    graph["B"] = {"C", "D"};
    graph["C"] = {"E"};
    graph["D"] = {"F"};
    graph["E"] = {"H", "F"};
    graph["F"] = {"G"};
    graph["G"] = {};
    graph["H"] = {};

    topologicalSort(graph);

    return 0;
}
