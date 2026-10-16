class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth) {
            long long cost=1LL*need1*cost1;
            cost+=(1LL*need2*cost2);
            return cost;
        }
        else {
            if(cost1<costBoth && cost2<costBoth) {
                long long mn=min(need1,need2);
                long long cost=mn*costBoth;
                if(mn==need2) {
                    cost+=(need1-mn)*cost1;
                }
                else {
                    cost+=(need2-mn)*cost2;
                }
                return cost;
            } else if(cost1>costBoth && cost2>costBoth) {
                long long mx=max(need1,need2);
                long long cost=mx*costBoth;
                return cost;
            } else if(cost1>costBoth) {
                long long mn=min(need1,need2);
                long long cost=mn*costBoth;
                if(mn==need2) {
                    cost+=(need1-mn)*costBoth;
                }
                else {
                    cost+=(need2-mn)*cost2;
                }
                return cost;
            } else {
                long long mn=min(need1,need2);
                long long cost=mn*costBoth;
                if(mn==need1) {
                    cost+=(need2-mn)*costBoth;
                }
                else {
                    cost+=(need1-mn)*cost1;
                }
                return cost;
            }
        }
        return 0;
    }
};