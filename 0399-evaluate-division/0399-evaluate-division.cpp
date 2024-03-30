class Solution {
    unordered_map<string, vector<pair<string, double>>> ump;
    unordered_map<string, bool> vis;
    double ansQuery;
public:

    bool dfs(string src, string dest, double stepans)
    {
        cout << src << " " << dest << endl;

        if(ump.find(src) == ump.end() || ump.find(dest) == ump.end())
        return false;

        if(src == dest && ump.find(src) != ump.end() ){
            ansQuery = stepans;
            return true;
        }
        vis[src] = true;
        vector<pair<string, double>> adj = ump[src];
        bool k = false;
        for(int i = 0 ; i < adj.size() ; i++){
            if(!vis[adj[i].first]){
                 k = dfs(adj[i].first, dest, stepans*(adj[i].second));
                if(k)
                break;
            }
        }
        vis[src] = false;
        return k;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int qu = queries.size();
        int m = equations.size();
        vector<double>ans;

        for(int i= 0 ; i < m ; i++){
            ump[equations[i][0]].push_back({equations[i][1], values[i]});
            ump[equations[i][1]].push_back({equations[i][0], (1/values[i])});
            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }

        for(int i = 0 ; i < qu ; i++){
            string src = queries[i][0];
            string dest = queries[i][1];

            ansQuery = 1;
            if(dfs(src, dest, 1))
            {
                ans.push_back(ansQuery);
            }
            else
            {
                ans.push_back(-1);
            }
            cout << "break\n";
        }

        return ans;



    }
};