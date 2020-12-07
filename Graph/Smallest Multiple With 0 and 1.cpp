link->https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/


===========Method 1(Not accepted on interviewbit)=================

int mod(string t, int N)
{
    int r = 0;
    for (int i = 0; i < t.length(); i++)
    {
        r = r * 10 + (t[i] - '0');
        r %= N;
    }
    return r;
}
string Solution::multiple(int A) {
    
    int N=A;
   queue<string> q;
    set<int> visit;
 
    string t = "1";
 
    //  In starting push 1 into our queue
    q.push(t);
 
    //  loop untill queue is not empty
    while (!q.empty())
    {
        // Take the front number from queue.
        t = q.front();      q.pop();
 
        // Find remainder of t with respect to N.
        int rem = mod(t, N);
 
        // if remainder is 0 then we have
        // found our solution
        if (rem == 0)
            return t;
 
        // If this remainder is not previously seen,
        // then push t0 and t1 in our queue
        else if(visit.find(rem) == visit.end())
        {
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "1");
        }
    }
}



=============================Interviewbit method===================================
//explanation in Notebook

string Solution::multiple(int A) {
   
   int N=A;
    if(N==1)
        return "1";
//state means remaider
    vector<int>parent(N,-1);//vlaue fo state range from 0 to N
    vector<int>stateFromParent(N,-1);

    //parent[i] stores from where this ith state came
    //stateFromParent[i] stores which step we choose{0 or 1} 
    // from prev state to make ith state

    queue<int>q;
    q.push(1);
    int steps[]={0,1};

    while(q.empty()==false)
    {

       int currState=q.front();
       q.pop();

       if(currState==0)
          break;

        
        for(int step:steps)
        {
            int nextState=(currState*10+step)%N;

            if(parent[nextState]==-1)
            {
                parent[nextState]=currState;
                stateFromParent[nextState]=step;
                q.push(nextState);
            }
        }
    }

    string number;

     //i is state
    //to build result we start from state 0
    for(int i=0;i!=1;i=parent[i])
    {
        number.push_back('0'+stateFromParent[i]);
    }
    number.push_back('1');

    return string(number.rbegin(),number.rend());
}


