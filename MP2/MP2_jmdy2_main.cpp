#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <utility> //pair
#include <algorithm> //sort


#define PII pair<int, int>
#define Edge pair<PII, PII>

class Graph {
    public:
        vector<vector<Edge>> G;
        void add_edge(Edge edge);
};

Graph g;

void Graph::add_edge(Edge edge) {
        G[edge.first.first].push_back(edge); //u
        G[edge.first.second].push_back(edge); //v
    }

class DisjointSet {
    public:
        void MakeSet(int N);
        int FindSet(int x);
        void Union(int x, int y);
};

DisjointSet d;

//The following code up until union method obtained from sir Neil's code_9_1
int* parent;
int* rnk;

void DisjointSet::MakeSet(int N) {
    parent = new int[N];
    rnk = new int[N];

    for(int i = 0; i < N; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int DisjointSet::FindSet(int x) {
    if(parent[x] != x) {
        x = FindSet(parent[x]);
        parent[x] = x;
    }
    return x;
}

void DisjointSet::Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);

    if(x != y) {
        if(rnk[x] > rnk[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if(rnk[x] == rnk[y]) {
               rnk[y]++;
            }
        }
    }
}


bool sortweight(const Edge& one, const Edge& two) { //https://www.geeksforgeeks.org/sort-vector-of-pairs-in-ascending-order-in-c/
    return one.second.first < two.second.first;
}

void kruskal(vector<Edge>& kruskal_pq, int K) {
    vector<Edge> MST;
    int counter = 0;
    int costs = 0;

    vector<Edge> servers; //vector for servers
        
        for (int i = 0; i < kruskal_pq.size(); i++) {
            Edge q = kruskal_pq[i];
            if (q.first.first < K && q.first.second < K) { //make sure the nodes (u and v) dont go over the server amount
                servers.push_back(q);
            }
        }
        sort(servers.begin(), servers.end()); //sorting by ascending

    while(!kruskal_pq.empty() && counter < K - 1) {
        
        Edge e = servers.front(); //.top() doesnt work [due to the pq being a vector of vectors or not being a stack], used alternative .front() https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/
        if(d.FindSet(e.first.first) != d.FindSet(e.first.second)) {
            costs += e.second.second; //adding the costs
            MST.push_back(e);
            counter++;
            d.Union(e.first.first,e.first.second);
        }
        kruskal_pq.erase(kruskal_pq.begin()); //.pop() doesnt work, used alternative .erase(position) https://www.shiksha.com/online-courses/articles/erasing-elements-from-a-vector-in-c/
    }
    if(counter == K - 1) {
        cout << "Hosting costs: " << costs << " USD" << endl;
        cout << "Server links:" << endl;
        for(int i = 0; i < MST.size(); i++) {
            cout << MST[i].first.first << " " << MST[i].first.second << " " << MST[i].second.first << "ms" << endl;
        }

    } else {
        cout << "No MST" << endl;
    }
}


void dijkstra(vector<vector<Edge>>& G, int N, int K) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> d_s(N, (1<<30)); //infinity distance
    vector<int> pre(N, -1);

    for (int i = 0; i < K; i++) { //initializing servers 
        d_s[i] = 0;
        pq.push(make_pair(0,i));
    }

    while(!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for(int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];

            if(d_s[e.first.second] > d_s[e.first.first] + e.second.first) {
                d_s[e.first.second] = d_s[e.first.first] + e.second.first; 
                pre[e.first.second] = e.first.first;
                pq.push(make_pair(d_s[e.first.second],e.first.second));
            }
        }
    }

    cout << "Ping of client from the nearest server:" << endl;
    for (int i = K; i < N; i++) {
        cout << i << ": " << d_s[i] << "ms" << endl;
    }
}
    

int main() {
    int T;
    int N,K,M;
    int u,v,w,x;
    cin >> T;
    
    for(int i = 0; i < T; i++) {

        cin >> N >> K >> M;
        // vector<Edge> MST;
        // priority_queue<Edge,vector<Edge>,EdgeComparator> edgeList;
        vector<Edge> kruskal_pq(M);
        

        Graph g;
        g.G.resize(N);
        for(int i = 0; i < M; i++) {
            cin >> u >> v >> w >> x;
            PII node_edge = make_pair(u, v);
            PII latency_cost = make_pair(w, x);
            Edge edge = make_pair(node_edge, latency_cost);
            kruskal_pq[i] = edge; 
            g.add_edge(edge);
        }
        sort(kruskal_pq.begin(), kruskal_pq.end(), sortweight);

        cout << "Test case #" << i+1 << ":" << endl;
        d.MakeSet(N);
        kruskal(kruskal_pq, K);
        dijkstra(g.G, N, K);
        
        delete[] rnk;
        delete[] parent;
        

        kruskal_pq.clear();
        g.G.clear();
        
    }
    return 0;
}