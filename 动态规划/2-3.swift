/*
 * 题目：零钱兑换
 * 链接：https://leetcode-cn.com/problems/coin-change/
 */

func coinChange(_ coins: [Int], _ amount: Int) -> Int {
    if amount <= 0 {
        return 0
    }
    if coins.count <= 0 {
        return -1
    }
    
    // dp[i]表示凑i元最少要dp[i]个硬币
    var dp = [Int](repeating: amount+1, count: amount+1)
    dp[0] = 0
    for i in 1...amount {
        for coin in coins {
            if i - coin >= 0 {
                dp[i] = min(dp[i], dp[i-coin]+1)
            }
        }
    }
    
    return dp[amount] == amount + 1 ? -1 : dp[amount]
}

