#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[],int vis[],int des,int x)
{
    vis[x]=1;
    if(des==x)
    {
        cout<<x<<" "<<des<<" true"<<endl;
        cout<<"congratulations element found: ";
        return;
    }
    else
    {
        cout<<x<<" "<<des<<"false"<<endl;
    }

    for(int i=0;i<graph[x].size();i++)
    {
        int temp=graph[x][i];

        if(vis[temp]==0)
        {
            dfs(graph,vis,des,temp);
        }
    }


}

void print(int root,vector<int> graph[])
{
    queue<int> q;
    q.push(root);
    int vis[1001]={0};
    while(!q.empty())
    {
        int k=q.size();
        for(int i=0;i<k;i++)
        {
            int x=q.front();
            q.pop();
            vis[x]=1;
            cout<<x<<" ";
            for(int i=0;i<graph[x].size();i++)
            {
                if(vis[graph[x][i]]==0)
                {
                    q.push(graph[x][i]);
                }
            }
        }
        cout<<endl;
    }
}
int main ()
{
  int n;
  cout<<"Enter number of level:";
  cin>>n;
  int m;
  cout<<"Enter max number of child:";
  cin>>m;
  int root=-1;
  int temp;
  queue<int> q;
  int f1=0;
  vector<int> graph[1001];
  while(true)
  {
      int t;
      if(f1==0)
      {
          cout<<"enter the node:";
          cin>>t;
          q.push(t);
          f1=1;
      }
      if(root==-1)
      {
          root=t;
      }
      int f;
      cout<<"how many child for "<<q.front()<<" you want to enter :";
      cin>>f;
      while(f>0)
      {
          int x;
          cout<<"enter the child for "<<q.front()<<" :";
          cin>>x;
          q.push(x);
          graph[q.front()].push_back(x);
          graph[x].push_back(q.front());
          f--;
      }
      q.pop();
      if(q.size()==0)
      {

             break;

      }
  }
  cout<<" tree looks like: ";
  print(root,graph);
  int des;
  cout<<"enter any value to search: ";
  cin>>des;
  int vis[1001]={0};
  queue<int> qu;
  qu.push(root);
  cout<<" traversal will goes as: "<<endl;
  dfs(graph,vis,des,root);


}
