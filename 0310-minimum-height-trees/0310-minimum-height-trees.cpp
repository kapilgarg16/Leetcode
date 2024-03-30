class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n == 0)
        return ans;
        if(edges.size() == 0)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int>adj[n];
        vector<int>it(n, 0);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            it[edges[i][1]]++;
            it[edges[i][0]]++;
        }

    queue<int>q;
    for(int i = 0 ; i < n ; i++){
        if(it[i] == 1){
            q.push(i);
        }
    }
    while(n > 2){
        int size = q.size();
        n = n - size;
        while(size != 0){
            int top = q.front();
            q.pop();
            for(auto &itr : adj[top]){
                    it[itr]--;
                    if(it[itr] == 1){
                        q.push(itr);
                    }
            }
            size--;
        }
    }
        while(!q.empty()){
            int top = q.front();
            ans.push_back(top);
            q.pop();
        }
        return ans;
    }
};