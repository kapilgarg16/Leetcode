class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& pre) {
        //it looks like topological sort
        vector<int>ans;
        if(n == 1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int>adj[n], it(n,0);

        for(int i = 0 ; i < pre.size() ; i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            it[pre[i][0]]++;
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            // cout << it[i] << " ";
            if(it[i] == 0){
                q.push(i);
            }
        }
        // cout<< endl;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            ans.push_back(tp);

            for(auto itr : adj[tp]){
                // cout << itr << " ";
                it[itr]--;
                if(it[itr] == 0){
                    q.push(itr);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(it[i] != 0)
            ans.resize(0);
        }
        return ans;
    }
};
