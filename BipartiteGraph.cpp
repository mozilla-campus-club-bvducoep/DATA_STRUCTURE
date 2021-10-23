#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int G[][4])
{
    queue<int> q;
    q.push(0);
    vector<int> color(4 , -1); // INITIALIZING NO COLOR TO EVERY VERTEX
    color[0] = 1;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            if(G[t][i] && color[i] == -1) {
                color[i] = 1 - color[t];
                q.push(i);
            }
            else if(G[t][i] && color[i] == color[t]) {
                cout<<t<<" "<<i<<endl;
                return false;
            }
        }
    }
    return true;

}

int main()
{

 int G[][4] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout<<(isBipartite(G) ? "YES" : "NO" )<<endl;

}
