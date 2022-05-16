#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

    void spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int> vis(V,0);
       int key[V];
       int par[V];
       for(int i=0;i<V;i++)
       {
           key[i]=INT_MAX;
           par[i]=-1;
       }
       int ans=0;
       priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
       key[0]=0;
       q.push({0,0});

       while(!q.empty())
       {
           pair<int,int> t=q.top();
           q.pop();
           int x=t.second;
           if(vis[x]==0)
           {
           vis[x]=1;
           ans=ans+key[x];
           if(x!=0)
           {
               cout<<par[x]<<" to "<<x<<" == "<<key[x]<<endl;
           }
           for(int i=0;i<adj[x].size();i++)
           {
               if(vis[adj[x][i][0]]==0 &&  key[adj[x][i][0]] > adj[x][i][1])
               {
                   par[adj[x][i][0]]=x;
                   key[adj[x][i][0]]=adj[x][i][1];
                   q.push({adj[x][i][1],adj[x][i][0]});
               }
           }
           }

       }


    }
};


int main()
{

        int V,E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout<<"minimum spanning tree ==>>"<<endl;
        obj.spanningTree(V, adj);

        return 0;
}
