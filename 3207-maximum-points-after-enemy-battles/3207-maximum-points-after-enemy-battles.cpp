class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n=enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(currentEnergy<enemyEnergies[0]) return 0;

        int l=0,r=n-1;
        long long ans=0;
        while(l<=r) {
            if(enemyEnergies[l]<=currentEnergy) {
                int v=currentEnergy/enemyEnergies[l];
                currentEnergy=currentEnergy%enemyEnergies[l];
                ans+=v;
            } else {
                currentEnergy+=enemyEnergies[r];
                r--;
            }
        }
        return ans;
    }
};