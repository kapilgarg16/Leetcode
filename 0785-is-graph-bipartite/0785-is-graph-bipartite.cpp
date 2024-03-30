class Solution {
public:
    //check the bipairate graph
    bool checkBip(int src, vector<bool> &vis, vector<int> &par, vector<vector<int>>& graph, int xr){
        vis[src] = true;
        par[src] = xr;

        // cout << src << endl;
        for(auto &it1 : graph[src]){
                if(!vis[it1]){
                    bool k = checkBip(it1, vis, par, graph, xr^1);
                    if(!k)
                    return false;
                }
                else if(par[src] == par[it1]){
                    return false;
                }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<int>par(n);

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == false && checkBip(i, vis, par, graph, 0) == false){
                return false;
            }
        }
        return true;
    }
};