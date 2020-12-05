link-->https://leetcode.com/problems/2-keys-keyboard/solution/
https://massivealgorithms.blogspot.com/2017/07/leetcode-650-2-keys-keyboard.html



We look for a divisor d so that we can make d copies of (n / d) to get n
The process of making d copies takes d steps (1 step of Copy All and d - 1 steps of Paste)
We keep reducing the problem to a smaller one in a loop.
The best cases occur when n is decreasing fast, and method is almost O(log(n))
For example, when n = 1024 then n will be divided by 2 for only 10 iterations, which is much faster than O(n) DP method.
The worst cases occur when n is some multiple of large prime, e.g. n = 997 but such cases are rare.
    public int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }

Point 1: the whole steps will be like this: CP..P CP..P CP..P. So in each segment, it's always like oneC with >=1's P. The answer is the length of this character array.
Point 2: once you reach to a non-divisor of n at the end of any segment, it's impossible to reach n anymore. The reason is: once you reach y at the end of segment, then all future operations lead to a number that is a multiple of y, but n is not a multiple of y, so it's impossible to reach n. This means you have to make sure that each segment leads to a number that is a divisor of n.
Point 3: there are many divisors to choose, which include n itself (corresponding to CPPP..PPP array with n-1 P). The best solution must choose one of them. Here we say the best solution always choose divisor that is not the special divisor n, because compared to the special divisor n, there is always a better divisor y to choose where 1<y<=sqrt(n) (if such y exists). If we choose n, then the length is one C and n-1 P so length is n. If we choose y where 1<y<=sqrt(n), then the length is at most y + (n / y) because there is at least one solution CPP..P CPP..P with first segment y-1 number of P, and second segment n/y - 1 number of P. With y's constraint, after some steps, we can see this length is always <=n. So if such y exists, then the best solution will choose one such y. This is the only "optimizing" step in the whole proof.
Point 4: we will reach to a point that it's always best to choose a prime divisor because non-prime divisor will continue the above process until no such y exists, or n becomes prime number.
Point 5: so the best solution must begin with a segment that leads to a prime divisor of n. For example, if n is 60, then the best solution either begins with a segment that reaches 2, or begins with a segment that reaches 3, or 5.
Point 6: once you reach to a divisor y through steps A=CP...P, then we just do new_n = n/y because we can attach array A as prefix to the array of new_n's solution array.
Point 7: with the above point, then the whole solution array of n is like this: one segment that reaches one prime divisor y, get a new n from n/y, then get another segment that reaches one prime divisor w (probably w=y), and get a new n.
Point 8: segment's order does not matter. CPPCPPPP reaches to the same number with CPPPPCPP.
Point 9: so then you will realize that the solution is like this. If n's prime factorization is p^a * q^b * r^c where p q r are prime divisors of n, then the whole array is one permutation of the segment array: a number of segment-1 "CPP...P" with p-1 P, b number of segment-2 "CPP..P" with q-1 P, c number of segment-3 "CPP..P" with r-1P. So the whole solution is: a*p + b*q + c*r.
Point 10: the given solution in this discussion thread is always beginning from smallest prime divisor, which makes it look like a greedy solution, but that we know it's a greedy solution gives us little value, because the correctness proof lies in prime factoring.
