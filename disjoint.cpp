#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
    vector<int>rank;
    vector<int>parent;
    vector<int>size;

    public : 

    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++) parent[i] = i;
    }

    int findUparent(int node) {
        if(node == parent[node])return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionByrank(int u,int v) {
        int pu = findUparent(u);
        int pv = findUparent(v);
        if(pu==pv) return;

        if(rank[pu] > rank[pv]) parent[pv] = pu;
        else if (rank[pu] < rank[pv]) parent[pu] = pv;

        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBysize(int u,int v){
        int pu = findUparent(u);
        int pv = findUparent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }  
    }

    
};
