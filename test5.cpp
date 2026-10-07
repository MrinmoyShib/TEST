#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<double> x = {2, 4, 6, 8, 10, 12};
    vector<double> y = {60, 72, 80, 84, 82, 74};
    int degree = 2;
    double xp = 7;
    int n = x.size(), m = degree + 1;

    vector<double> S(2 * degree + 1);

    for (int k = 0; k <= 2 * degree; k++)
    {
        for (int j = 0; j < n; j++)
        {
            S[k] += pow(x[j], k);
        }
    }

    vector<vector<double>> A(m, vector<double>(m + 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = S[i + j];
        }
        for (int j = 0; j < n; j++)
        {
            A[i][m] += pow(x[j], i) * y[j];
        }
    }

    for (int k = 0; k < m-1; k++)
    {
        for (int i = k + 1; i < m; i++)
        {
            double f = A[i][k] / A[k][k];

            for (int j = k; j <= m; j++)
            {
                A[i][j] -= f * A[k][j];
            }
        }
    }

    vector<double> c(m);

    c[m - 1] = A[m - 1][m] / A[m - 1][m - 1];

    for (int k = m - 2; k >= 0; k--)
    {
        double sum = 0;

        for (int j = k + 1; j < m; j++)
        {
            sum += A[k][j] * c[j];
        }
        c[k] = (A[k][m] - sum) / A[k][k];
    }

    auto f = [&](double v)
    {
        double r = 0;
        for (int i = 0; i < m; i++)
        {
            r += c[i] * pow(v, i);
        }
        return r;
    };
    double mse = 0;
    for (int i = 0; i < n; i++)
        mse += pow(y[i] - f(x[i]), 2);
    mse /= n;



    
    cout << fixed << setprecision(4);

    cout << "Coefficients: ";
    for (int i = 0; i < m; i++)
    {
        cout << (char)('a' + i) << " = " << c[i];
        if (i < m - 1)
            cout << ", ";
    }
    cout << "\n";

    cout << "Polynomial Regression Equation: y = " << c[0];
    for (int i = 1; i < m; i++)
        cout << " " << (c[i] < 0 ? '-' : '+') << " " << fabs(c[i]) << "x^" << i;
    cout << "\n";

    cout << "Predicted value at x = " << defaultfloat << xp << fixed << ": " << f(xp) << "\n";

    cout << setprecision(6) << "MSE: " << mse << "\n";

    return 0;
}