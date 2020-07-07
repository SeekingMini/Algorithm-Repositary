/*
 * 题目：零钱兑换 II
 * 链接：https://leetcode-cn.com/problems/coin-change-2/
 */
func change(_ amount: Int, _ coins: [Int]) -> Int {
    if amount <= 0 {
        return 1
    }

    let l = coins.count
    if l <= 0 {
        return 0
    }
    
    // dp[i][j]表示选择前i个硬币凑足j元有dp[i][j]种方法
    var dp = [[Int]](repeating: [Int](repeating: 0, count: amount+1), count: l+1)
    // 初始化dp数组
    for i in 0...l {
        dp[i][0] = 1
    }
    
    // 动态规划
    for i in 1...l {
        for j in 1...amount {
            if j - coins[i-1] >= 0 {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
            } else {
                dp[i][j] = dp[i-1][j]
            }
        }
    }
    
    return dp[coins.count][amount]
}

