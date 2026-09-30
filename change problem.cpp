#include <iostream>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coins[100];

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] stores minimum coins needed to make amount i
    int dp[1000];

    // Initialize
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = 9999;
    }

    // Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] == 9999)
    {
        cout << "Change cannot be made";
    }
    else
    {
        cout << "Minimum number of coins = " << dp[amount];
    }

    return 0;
}
