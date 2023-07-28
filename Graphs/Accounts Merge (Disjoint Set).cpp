class disjointSet {
    vector<int> rank, parent, size;
public:
    //constructor to assign initial values
    disjointSet(int n){
        rank.resize(n + 1, 0); //resizing so it works in 0-based or 1-based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i=0; i<=n; i++){
            parent[i] = i; //assign the parent array values
        }
    }
    //function to find ultimate parent
    int findUPar(int node){
        //base case
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); //ultimate parent of u
        int ulp_v = findUPar(v); //ultimate parent of v

        if(ulp_u == ulp_v)  return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{ //if size of v is greater
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //step 1-> connecting the nodes and making disjoint Set
        int n = accounts.size();
        disjointSet ds(n);
        unordered_map<string, int> mailToNode; //mapping of mails to indexes(nodes)
        //i'th loop for index
        for(int i=0; i<n; i++){
            //j'th loop for mails (0'th index has name and mails start after that. So, j=1)
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                //if that mail is not found
                if(mailToNode.find(mail) == mailToNode.end()){
                    mailToNode[mail] = i; //map to an index
                }
                //if it is found
                else{
                    ds.unionBySize(i, mailToNode[mail]); //combine the index and mails
                }
            }
        }

        //Step 2 -> merging the mails acc to disjoint set DS
        vector<vector<string>> mergedMail(n);
        for(auto it : mailToNode){
            string mail = it.first;
            int node = ds.findUPar(it.second); //finding the ultimate parent to connect mail 
            mergedMail[node].push_back(mail);
        }

        //step 3-> rearranging the set to get final vector
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0)   continue; //if the index has no mails, then continue
            sort(mergedMail[i].begin(), mergedMail[i].end());//sort the mails
            vector<string> temp;
            temp.push_back(accounts[i][0]);//first push the name according to the index
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
