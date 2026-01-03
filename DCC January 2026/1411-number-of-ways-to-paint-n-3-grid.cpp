#include <vector>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        
        // dp[i][0] = number of ways to paint first i rows ending with type A (ABC pattern)
        // dp[i][1] = number of ways to paint first i rows ending with type B (ABA pattern)
        long long typeA = 6; // 6 ways: RGB, RGY, GRY, GRB, YRG, YRB
        long long typeB = 6; // 6 ways: RGR, RGY, GRG, GRY, YRY, YRG
        
        for (int i = 2; i <= n; i++) {
            long long newTypeA = (2 * typeA + 2 * typeB) % MOD;
            long long newTypeB = (2 * typeA + 3 * typeB) % MOD;
            typeA = newTypeA;
            typeB = newTypeB;
        }
        
        return (typeA + typeB) % MOD;
    }
};