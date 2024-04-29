#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main() {
    int N,M;
    int u,v;

    vector< vector<int> > adj_list;
    
    bool* visited;

    //use undirected graph as input
    cin >> N >> M;
    int adj_mat[N][N];

    adj_list.resize(N);
    visited = new bool[N];

    for (int i = 0; i < N; i++) { //initialize matrix with 0
        for (int j = 0; j < N; j++) {
            adj_mat[i][j] = 0;
        }}

    for(int i = 0; i < M; i++) { //mark the adjacent nodes with 1
        cin >> u >> v;
        adj_mat[u][v] = 1;
        // adj_mat[v][u] = 1;
    }

    for(int i = 0; i < N; i++) {
        visited[i] = false;
    }

    int userinput;
    cin >> userinput;
    if (userinput == 1){
        queue<int> bfs_queue;   
    
        bfs_queue.push(0);
        
        visited[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << adj_mat[i][j] << " ";
            }
            cout << endl;
            }
        while(!bfs_queue.empty()) {
            int u = bfs_queue.front();
            // int u = bfs_queue.top();
            bfs_queue.pop();
            cout << char(u + 'A') << " ";
            for(size_t i = 0; i < N; i++) {
                int v = i;
                if(!visited[v] && (adj_mat[u][v] == 1)) { //will push to queue only if v is adjacent to u
                    visited[v] = true; // if visited, will never return to it
                    bfs_queue.push(i);
                }
            }
        }

        cout << endl;

        delete[] visited;
    }
        
        
    else {
        stack<int> dfs_stack;
        dfs_stack.push(0);
        
        visited[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << adj_mat[i][j] << " ";
            }
        cout << endl;
        }
        while(!dfs_stack.empty()) {
            int u = dfs_stack.top();
            dfs_stack.pop();
            cout << char(u + 'A') << " ";
            for(size_t i = 0; i < N; i++) {
                int v = i;
                if(!visited[v] && (adj_mat[u][v] == 1)) { //will push to stack only if v is adjacent to u
                    visited[v] = true;
                    dfs_stack.push(v);
                }
            }
        }

        cout << endl;
        
        delete[] visited;
    }

    return 0;
}