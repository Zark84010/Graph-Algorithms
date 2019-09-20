#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &vis, vector<vector<int> >g){
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]) continue;
        dfs(v,vis,g);
    }
}

int main(){
    IOS;
    vector<vector<int> > g;
    int V,E;
    cin>>V>>E;
    g.resize(V+10);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;
    for(int i=1;i<=V;i++){
        for(int j=0;j<g[i].size();j++) cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    vector<bool> vis(V+5, false);
    int countComponents=0;
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            dfs(i,vis,g);
            countComponents++;
        }
    }
    cout<<"Number of connected components are: "<<countComponents;
    return 0;
}
