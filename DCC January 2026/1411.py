class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        
        # Generate all valid patterns for a single row
        # Each cell can be 0, 1, or 2 (representing 3 colors)
        # Adjacent cells must have different colors
        p = []
        for i in range(3):
            for j in range(3):
                if i != j:
                    for k in range(3):
                        if j != k:
                            p.append((i, j, k))
        
        # Build adjacency list: np[i] contains all patterns that can follow pattern p[i]
        # Two patterns are compatible if no cell has the same color in both rows
        np = []
        for i in range(len(p)):
            np.append([])
            for j in range(len(p)):
                good = True
                for k in range(3):
                    if p[i][k] == p[j][k]:
                        good = False
                        break
                if good:
                    np[i].append(j)
        
        # DP: dp[i] = number of ways to reach pattern i in current row
        dp = [1] * len(p)  # First row: 1 way to reach each pattern
        
        for row in range(1, n):
            new_dp = [0] * len(p)
            for i in range(len(p)):
                for j in np[i]:  # j can follow i
                    new_dp[j] = (new_dp[j] + dp[i]) % MOD
            dp = new_dp
        
        return sum(dp) % MOD
