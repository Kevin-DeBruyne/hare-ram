#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
        vector<int> key(V);
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX;
        }

        key[S]=0;
        q.push({0,S});
        int vis[V]={0};
        while(!q.empty())
        {
            pair<int,int> t=q.top();
            q.pop();
            int x=t.second;
            int y=t.first;
            if(vis[x]==0)
            {
            vis[x]=1;
            for(int i=0;i<adj[x].size();i++)
            {
                int dis=adj[x][i][1];

                if( vis[adj[x][i][0]]==0 && y+dis<key[adj[x][i][0]])
                {
                    key[adj[x][i][0]]=y+dis;

                    q.push({key[adj[x][i][0]],adj[x][i][0]});
                }
            }
            }
        }

        return key;

    }
};
int main()
{

        int V, E;
        cout<<"enter number of vertices and edges:"<<endl;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E)
        {
            int u, v, w;
            cout<<"enter the source ,destination and weight"<<endl;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cout<<"enter the source point"<<endl;
        cin>>S;

        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);

    	for(int i=0; i<V; i++)
        {
    	    cout<<res[i]<<" ";
        }
    	cout<<endl;


    //return 0;
}
