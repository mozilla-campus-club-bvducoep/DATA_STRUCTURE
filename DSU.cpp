class DSU
{
    vector<int> par , rnk;
public :
    DSU(int n)
    {
        par.resize(n + 1);
        rnk.resize(n + 1);
        for(int i = 0 ; i<=n ; i++) {
            par[i] = i;
            rnk[i] = 0;
        }
    }
    int find_parent(int m)
    {
        if(par[m] == m)
            return m;
        return par[m] = find_parent(par[m]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rnk[a] < rnk[b])
                swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b])
                rnk[a]++;
        }
    }
};
