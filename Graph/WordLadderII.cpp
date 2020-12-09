

//First we make a graph between begin to endword using BFS so the graph contains smallest path b/w begin and end
//and after that we use dfs to store result


class Solution {
    
    void dfs(string beginWord, string endWord, unordered_map<string,unordered_set<string>>&adj,vector<vector<string>>&res,vector<string>&temp)
    {
        temp.push_back(beginWord);
        
        if(beginWord==endWord)
        {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(auto x :adj[beginWord])
        {
            dfs(x,endWord,adj,res,temp);
            
        }
        
        temp.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<string>>res;
        vector<string>temp;
        
        unordered_set<string>dict(wordList.begin(),wordList.end());
       unordered_map<string,unordered_set<string>>adj;
        
        unordered_map<string,int>vis;  //It stores if curr word is reachable or not
        queue<string>q;                 // and what is its distance from beginword
        q.push(beginWord);
        vis[beginWord]=0;
      
        while(q.empty()==false)
        {
            string word=q.front();
            q.pop();
           
            string org=word;
            for(int i=0;i<word.length();i++)
            {
                char curr=word[i];
               
                
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    
                    if(dict.find(word)!=dict.end())
                    {
                        if(vis.count(word)==0)
                        {
                            vis[word]=vis[org]+1;
                            adj[org].insert(word);
                            q.push(word);
                        }
                        else if(vis[word]==vis[org]+1)     //it means word is alredy been include 
                             adj[org].insert(word);        //if and only if distance of (word from  begin word ==dist of org+1)is same as we also include it in this new word 
                    }
                }
                
                word[i]=curr;
            }
            
           
        }
        
        
         dfs(beginWord,endWord,adj,res,temp);
        return res;
        
      
        
        
        
    }
};
