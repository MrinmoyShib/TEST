#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 3;
    vector<vector<double>> a = {
        {4, 1, -1, 3},
        {2, 5, 1, 15},
        {1, -1, 3, 8}};

    auto printMat = [&]()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << fixed << setprecision(4) << setw(10) << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };

    for (int k = 0; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double f = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++)
            {
                a[i][j] -= f * a[k][j];
            }
        }

        cout << "After step " << k + 1 << " : " << endl;
        printMat();
    }

    vector<double> x(n);
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (int k = n - 2; k >= 0; k--)
    {
        double sum = 0;
        for (int j = k + 1; j < n; j++)
        {
            sum += a[k][j] * x[j];
        }
        x[k] = (a[k][n] - sum) / a[k][k];
    }
    cout << "Solution:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(6)
             << x[i] << endl;
    }

    return 0;
}