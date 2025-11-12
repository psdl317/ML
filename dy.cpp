#include <bits/stdc++.h>
using namespace std;
int knapSack(int cap, int wt[], int val[], int n)
{
    int dp[n + 1][cap + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < cap + 1; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][cap];
}
int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    int val[n], wt[n];
    cout << "Enter values and weights of items:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }
    int cap;
    cout << "Enter knapsack capacity: ";
    cin >> cap;
    cout << "Maximum value in Knapsack = " << knapSack(cap, wt, val, n);
    return 0;
}