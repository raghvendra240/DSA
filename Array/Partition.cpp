link->https://www.interviewbit.com/problems/partitions/

====================Using Backtracking============
int res;
int part;

void help(vector<int>&nums,int index,int remain)
{
     if(remain==0 && index==nums.size())
      {
        
          res++;
          return;
      }

    
    if(remain==0 && index<nums.size())
               return;

     
    int temp=0;
       for( ;index<nums.size();index++)
       {
           temp+=nums[index];
      
           
           if(temp==part)
           {
               help(nums,index+1,remain-1);
           }
           
          
       }
}

int Solution::solve(int A, vector<int> &B) {
    
    int sum=0;
    for(int x:B)
     sum+=x;
  
       res=0;
       part=sum/3;
      
       help(B,0,3);
    
       return res;
       
}

==========================using prefix/suffix========================


int Solution::solve(int A,vector &B){
int sum=B[0];
    int prefix[A];
    int suffix[A];
    int ways=0;
    prefix[0]=B[0];
    suffix[A-1]=B[A-1];

    for(int i=1;i<A;i++)

    {

        sum+=B[i];
        prefix[i]=B[i]+prefix[i-1];
        suffix[(A-1)-i]=B[(A-1)-i]+suffix[(A-1)-(i-1)];
        

    }

    if(sum%3==0)

    {

        int x=sum/3;

        

        for(int i=0;i<A;i++)

        {

            if(prefix[i]==x)

            {

                for(int j=(A-1);j>=(i+2);j–)

                {

                    if(suffix[j]==x)

                    {

                        ways++;

                        continue;

                    

                    }

                }

            }

            

        }

    }

    else if((sum%3)!=0)
    {ways=0;}
    

    
    return ways; 
}

