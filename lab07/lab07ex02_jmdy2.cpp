#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// void printAdjList(vector<vector<int>> &adj_list,vector<string> &apparel) {
//     for (int i = 0; i < adj_list.size(); i++) {
//         cout << apparel[i] << "->";
//         for (int v : adj_list[i]) {
//             cout << apparel[v] << " ";
//         }
//         cout << endl;
//     }
// }


void toposort(int u, vector< vector<int> > &adj_list, bool* visited, queue<int> &topo_stack) {
    visited[u] = true;

    for(vector<int>::size_type i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
        if(!visited[v]) {
            toposort(v,adj_list,visited,topo_stack);
        }
    }
    
    topo_stack.push(u);
}

int main() {
    int N,M;
    int u,v;
    vector< vector<int> > adj_list;
    bool* visited;
    string* apparel;

    cin >> N >> M;
    cin.get();
    
    adj_list.resize(N);
    visited = new bool[N];
    apparel = new string[N];

    for(int i = 0; i < N; i++) {
        cin >> apparel[i];
        visited[i] = false;
    }

    for(int  i =0; i < M; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    queue<int> topo_stack;
    // topo_stack.push(0);
    for(int i =0; i < N; i++) {
        if(!visited[i]) {
            toposort(i, adj_list, visited, topo_stack);
        }
    }
    // printAdjList(adj_list, apparel[topo_stack.front()] );

    while(!topo_stack.empty()) {
        cout << apparel[topo_stack.front()];
        topo_stack.pop();

    }
    // while(!topo_stack.empty()) {
    //     cout << apparel[topo_stack.top()];
    //     topo_stack.pop();
    //     if(topo_stack.size()) {
    //         cout << " -> ";
    //     }
    // }
    cout << endl;

    delete[] visited;
    delete[] apparel;

    return 0;
}