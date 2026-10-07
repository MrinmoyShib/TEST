#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;

    vector<vector<double>> a = {
        {10, 2, 1, 13},
        {1, 5, 1, 7},
        {2, 3, 10, 15}};

    double allowed_error = 0.0001;
    int maxIter = 1000;

    vector<double> x(n), temp(n);

    for (int i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }

    int iter = 0;
    double temperror;

    cout << "Iter";

    for (int i = 0; i < n; i++)
    {
        cout << setw(13) << "x" << i + 1;
    }

    cout << setw(14) << "max error" << endl;

    do
    {
        temperror = 0;
        for (int k = 0; k < n; k++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != k)
                {
                    sum += a[k][j] * x[j];
                }
            }
            temp[k] = (a[k][n] - sum) / a[k][k];
            temperror = max(temperror, fabs(x[k] - temp[k]));
        }

        x = temp;
        iter++;

        cout << setw(4) << iter;

        for (int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(6)
                 << setw(13) << x[i];
        }

        cout << fixed << setprecision(6)
             << setw(14) << temperror << endl;

    } while (temperror >= allowed_error && iter < maxIter);

    cout << endl;
    cout << "Solution (after " << iter << " iterations):" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(6)
             << x[i] << endl;
    }

    return 0;
}