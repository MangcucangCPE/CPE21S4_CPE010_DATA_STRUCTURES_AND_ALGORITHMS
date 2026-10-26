
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getMinSteps(int n)
{
    vector<int> dp(n + 1);

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];

        if (i % 2 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 2]);

        if (i % 3 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 3]);
    }

    return dp[n];
}

int main()
{
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Please enter a positive integer.\n";
        return 0;
    }

    cout << "Minimum number of steps: "
         << getMinSteps(n) << endl;

    return 0;
}
