#include <bits/stdc++.h>
using namespace std;
vector<int> bell(int V,vector<vector<int>> &edges,int src){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(vector<int> &edge : edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(vector<int> &edge : edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
            cout<<"Negative edge cycle found.";
            return {};
        }
    }
    return dist;
}
int main(){
    int V,src,E;
    cout<<"Enter number of Vertices: \n";
    cin>>V;
    cout<<"Enter number of Edges: \n";
    cin>>E;
    cout<<"Enter Source : \n";
    cin>>src;
    vector<vector<int>> edges(E,vector<int>(3));
    
    for(int i=0;i<E;i++){
        cout<<"Enter edge (u v w): \n";
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    vector<int> distances=bell(V,edges,src);
    cout<<"Vertex Distance from Source\n";
    for(int i=0;i<V;i++){
        cout<<i<<" "<<distances[i]<<"\n";
    }
}