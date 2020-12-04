class Solution {
public:
    bool dfs(int i , vector<vector<int>>&adjGraph, int parent,vector<bool>&visited)
    {
       //if we visited this node before, then this forms a cycle
        if(visited[i] == true)
            return false;
       
        
        visited[i] = true;
        
        for(auto neigh: adjGraph[i])
        {
           //loop through all neighbors for the current node only if the neighbor is not the parent node (1->2->1)
            if(parent!=neigh)
            {
                if(dfs(neigh,adjGraph,i,visited)==false)
                    return false;
            }
        }
        
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        //tree 1. -> all nodes should be connected 
        //     2. -> it should not force a cycle
        vector<vector<int>>adjGraph(n);
        for(auto &edge: edges)
        {
            adjGraph[edge[0]].push_back(edge[1]);
            adjGraph[edge[1]].push_back(edge[0]);
        }
        
        if(dfs(0,adjGraph,-1,visited)==false)
            return false;
        for(int i =0; i < n; i++)
        {
            if(visited[i] == false)
            {
                 return false;
            }
               
        }
        
        return true;
    }
};
