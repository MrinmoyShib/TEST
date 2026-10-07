#include <bits/stdc++.h>
using namespace std;

int main()
{
    int MODE = 1;
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {3.0, 8.6, 15.9, 24.1, 33.5};

    double xp = 6;

    int n = x.size();

    double sX = 0, sX2 = 0, sY = 0, sXY = 0;

    for (int i = 0; i < n; i++)
    {
        double X = (MODE == 1) ? log(x[i]) : x[i];
        double Y = log(y[i]);

        sX += X;
        sX2 += X * X;
        sY += Y;
        sXY += X * Y;
    }

    double b = (n * sXY - sX * sY) / (n * sX2 - sX * sX);
    double A = (sY - b * sX) / n;
    double a = exp(A);

    auto f=[&](double v)
    {
        return (MODE == 1) ? a * pow(v, b) : a * exp(v * b);
    };


    double mse = 0;

    for(int i = 0;i<n;i++){
        mse += pow(y[i]-f(x[i]),2);
    }
    mse /=n;

    cout << fixed << setprecision(6);
 
    cout << "a = " << a << ", b = " << b << endl;
 
    if (MODE == 1)
    {
        cout << "Equation: y = "
             << a << " * x^" << b << endl;
    }
    else
    {
        cout << "Equation: y = "
             << a << " * e^(" << b << " x)" << endl;
    }
 
    cout << "Predicted value at x = " << xp
         << ": " << setprecision(4) << f(xp) << endl;
 
    cout << "MSE: "
         << setprecision(6) << mse << endl;


    return 0;
}