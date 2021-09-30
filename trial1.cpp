#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

vector<int> dijkstra(int source, vector<vector<pair<int, int> > > G)    {
    int INF = (int)1e9;
    int n = G.size();
    vector<int> D(n, INF);
    D[source] = 0;
    set<pair<int, int> > Q;
    Q.insert({0,source});
    while(!Q.empty())   {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
            if( D[u] + weight < D[v] ) {
                Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
            }
        }
    }
    return D;
}
// Driver code
int main()
{
	int v=1000, m=500,t;
    vector<pair<int, int> > adj[V];
    vector<int> memberID[m];
	int total, nodes;    
    cin>>total;
    for(int i= 0;i<total;i++){
    	cin>>t;
    	member.pushback(t);
	}
    cin>>nodes;
    int follower,following, time;
    for(int i= 0;i<nodes;i++){
    cin>>follower>>following>>time;
    addEdge(adj, follower, following, time);
	}
	dijkstra(follower)
    printGraph(adj, V);
    return 0;
}
