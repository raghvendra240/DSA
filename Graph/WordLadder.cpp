link->https://leetcode.com/problems/word-ladder/


class Solution {
    

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>dict(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,0});
       
        int level=0;
        int nodeL=q.size();
        while(q.empty()==false)
        {
            auto pair=q.front();
            q.pop();
            string word=pair.first;
            
            int index=pair.second;
            
             if(word==endWord)
                    { 
                       return index+1;
                    }
            
            for(int i=0;i<word.length();i++)
            {
                char curr=word[i];
                
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    
                    if(dict.find(word)!=dict.end())
                    {
                         q.push({word,index+1});
                         dict.erase(word);  //its like mark it visited
                    }
                }
                
                word[i]=curr;
            }

            
            
        }
        
      return 0;
       
    }
};
