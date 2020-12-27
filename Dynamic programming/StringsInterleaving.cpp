Give three strings ‘m’, ‘n’, and ‘p’, write a method to find out if ‘p’ has been formed by interleaving ‘m’ and ‘n’.
‘p’ would be considered interleaving ‘m’ and ‘n’ if it contains all the letters from ‘m’ and ‘n’ and the order of letters is preserved too.

Input: m="abd", n="cef", p="abcdef"
Output: true
Explanation: 'p' contains all the letters from 'm' and 'n' and preserves their order too.


solution:

base case:

  if(all i,j,k reaces end)
    return true;
   if(i==p.size() but either j!=0 or k!=0)
     return false;

make three var i@p, j@m and k@n

if(p[i]==m[i])
{ 
 now recure for next and if true then return true
}

if(p[i]==n[k]
{now recure for next and if true then return true
}

return false if none of above return true
