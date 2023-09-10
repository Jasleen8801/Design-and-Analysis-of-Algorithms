def min_coins_dp(coins, amount, n):
  dp = [[0 for _ in range(amount + 1)] for _ in range(n + 1)]
  for i in range(n + 1):
    dp[i][0] = 0
  for j in range(1, amount + 1):
    dp[0][j] = float('inf')

  for i in range(1, n + 1):
    for j in range(1, amount + 1):
      if coins[i - 1] > j:
        dp[i][j] = dp[i - 1][j]
      else:
        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]])

  return dp[n][amount]


def main():
  coins = [1, 5, 10]
  amount = 11
  n = len(coins)

  print(min_coins_dp(coins, amount, n))


if __name__ == "__main__":
  main()
