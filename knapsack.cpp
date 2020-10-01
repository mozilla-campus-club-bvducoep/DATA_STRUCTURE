#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n,w;
	// n is number of items
	//w is max weight 
map<pair<ll,ll>,ll> mp;
ll ks(ll W,ll wt[],ll v[],ll i) // W to store remaining Weight I can accomodate
{
	if(i==n || W <=0) 
		return 0;
	else
	{
		if(wt[i]>W)
		{
			if(mp.find(make_pair(W,i))!=mp.end()) //if already stored
				return mp[make_pair(W,i)];
			else			
				return mp[make_pair(W,i)]=ks(W,wt,v,i+1);
		}
		else
		{
			if(mp.find(make_pair(W,i))!=mp.end())
				return mp[make_pair(W,i)];
			else
				return mp[make_pair(W,i)]=max(v[i]+ks(W-wt[i],wt,v,i+1), ks( W, wt, v, i+1));// Either include that particular item, or leave it!
		}
		
	}
	
}
int main()
{	
	
	cin >> n >> w;
	ll v[n],wt[n];
	//wt[] array to store weights of 'n' items
	for(ll i=0;i<n;i++)
	{
		cin >> wt[i] >> v[i];
	}
	
	ll ans = ks(w,wt,v,0);	
	cout << ans << endl;

}
