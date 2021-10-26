#include<bits/stdc++.h>
using namespace std;

int vis[1007];
stack<int> s;
vector<int> graph[1007]; // GRAPH

void dfs(int p)
{
    vis[p] = 1;
    for(auto it : graph[p]) {
        if(!vis[it]) {
            dfs(it);
        }
    }
    s.push(p);

}

int main()
{

    // ADDING EDGES
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(0);

    for(int i = 0 ; i <= 5 ; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

}
