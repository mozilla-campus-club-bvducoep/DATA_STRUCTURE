//Program for topological sort 
#include<bits/stdc++.h>
using namespace std;
#define sz 100001

vector<int>g[sz];
vector<int>ans; //storing topological sorted vertex
int indeg[sz];
int main()
{
    int V,E;
    cin>>V>>E; 
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        indeg[v]++;
        g[u].push_back(v); //making one directional graph
    }
    priority_queue<int, vector<int>, greater<int> >q; 
    for(int i=1; i<=V; i++)
    {
        if(indeg[i]==0) { q.push(i); }
        
    }
    while(!q.empty())
    {
        int u=q.top();

        q.pop();
        ans.push_back(u);
        for(int i=0; i<g[u].size(); i++)
        {
            indeg[g[u][i]]--;
            if(indeg[g[u][i]]==0)
            {
                q.push(g[u][i]); //decreasing indeg
            }
        }
    }
    for(int i=0;i<V; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}