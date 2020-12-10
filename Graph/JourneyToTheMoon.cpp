link->https://www.hackerrank.com/challenges/journey-to-the-moon/problem

/*

We need to find the distinct sets (i.e. if x and y are from same country, they belong to same set) to get the answer. Let's say set A has a elements,set B has b elements.

Answer = a x b. [Because actual formula is to select one from set A and another one from set B = aC1 x bC1 = a x b]

Similarly, let's calculate answer for 4 sets - A,B,C,D with a,b,c,d elements respectively.

Lets say somehow I find set A has a elements.

Answer = 0 (Since I don't have another country to pair with)

Now, I find set B with b elements.

Answer = axb; .................................................(1)

Then, I find set C with c elements.

Answer = (axb) + (axc) + (bxc) [because we can select a pair from A and B, or A and C or B and C]

But this can be written as

Answer = (axb) + (a+b)xc ......................................(2)

Now I find set D with d elements, and I've examined all people.

Answer = (axb) + (axc) + (axd) + (bxc) + (bxd) + (cxd)

Or

Answer = (axb) x (a+b)xc + (a+b+c)xd ..........................(3)

Do you see the pattern? That means when we find a new set, the new answer is the old answer + the sum of old values x new value.


*/


void dfs(int u,vector<int>adj[],vector<bool>&vis,int &count)
{
    vis[u]=true;
    count++;//
    for(int v:adj[u])
    {
        if(vis[v]==false)
        {
            //count++;
            vis[v]=true;
            dfs(v,adj,vis,count);
            
            
        }
    }
    
    return;
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
if(n==1 || n==0)
 return 0;
   vector<int>adj[n];
   
   for(int i=0;i<astronaut.size();i++)
   {
       adj[astronaut[i][0]].push_back(astronaut[i][1]);
       adj[astronaut[i][1]].push_back(astronaut[i][0]);
   }
   
   int res=0;
   vector<bool>vis(n,false);
   vector<int>temp;
   for(int i=0;i<n;i++)
   {
       if(vis[i]==false)
       {
           int count=0;
           dfs(i,adj,vis,count);
        //    res=res*count;
        temp.push_back(count);
       }
   }
   
   int k=temp.size();

   int sum = 0;
   int result = 0;
for(int size : temp)
 {
   result += sum*size;
   sum += size;    
 }   
return result;
}
