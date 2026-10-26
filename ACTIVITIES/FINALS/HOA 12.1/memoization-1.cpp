
#include <iostream>
#include <algorithm>
using namespace std;

int *memo;

int getMinSteps(int n)
{
    if (n == 1)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int r = 1 + getMinSteps(n - 1);

    if (n % 2 == 0)
        r = min(r, 1 + getMinSteps(n / 2));

    if (n % 3 == 0)
        r = min(r, 1 + getMinSteps(n / 3));

    memo[n] = r;

    return r;
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

    memo = new int[n + 1];

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    memo[1] = 0;

    cout << "Minimum number of steps: "
         << getMinSteps(n) << endl;

    delete[] memo;

    return 0;
}
