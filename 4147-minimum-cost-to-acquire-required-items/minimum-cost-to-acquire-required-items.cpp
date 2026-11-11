class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = 1LL * need1*cost1 +1LL * need2*cost2;
        long long c2 = 1LL * max(need1,need2)*costBoth;
        long long mini =1LL * min(need1,need2);
        long long c3 = 1LL * mini*costBoth + 1LL *(need1-mini)*cost1 + 1LL *(need2-mini)*cost2;

        return min({c1,c2,c3});
    }
};