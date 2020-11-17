class Solution {
public:
    //if you can not reach destiniation from all paths, then the function return false;
    bool dfs(vector<vector<int>>&adjGraph, int current, vector<bool>&visited, int destination)
    {
        if(adjGraph[current].empty())
        {
            return current==destination;
        }

        //reach a cycle
        if(visited[current] == true)
        {
            return false;
        }
        
        visited[current] = true;
        bool result = true;
        for(int i = 0; i < adjGraph[current].size();i++)
        {
            int edge = adjGraph[current][i];
            if(!dfs(adjGraph,edge,visited,destination))
            {
                result = false;
                break;
            }
            
        }
        visited[current] = false;
        return result;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjGraph(n);
        for(int i = 0; i < edges.size();i++)
        {
            int from = edges[i][0], to = edges[i][1];
            adjGraph[from].push_back(to);
        }
        if(!adjGraph[destination].empty()) return false;
        vector<bool>visited(n,false);
        //start from every route from Source, check whether they could reach destination 
        
        //Also it can construct a memo to memorize whether one node can reach destiniation 
        return dfs(adjGraph,source,visited,destination);

        
        //return true;
    }
};
