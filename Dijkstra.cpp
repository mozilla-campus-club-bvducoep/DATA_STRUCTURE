#include<bits/stdc++.h> 
using namespace std; 
const int INF=1000000;
  
typedef pair<int, int> iPair; 
  
class Graph 
{ 
    int V;  
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V); 
    void addEdge(int u, int v, int w); 
    void shortestPath(int s); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back({v, w}); 
    adj[v].push_back({u, w}); 
} 
  
void Graph::shortestPath(int src) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    vector<int> dist(V, INF); 
    pq.push({0, src}); 
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
    printf("Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
int main() 
{ 
    int V,E; 
    cin>>V>>E;
    Graph g(V); 
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }  
    g.shortestPath(0); 
  
    return 0; 
} 