#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    bool showSteps = true;
    int n = 3;

    vector<vector<double>> a = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    auto printMat = [&]()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << fixed << setprecision(4)
                     << setw(10) << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };

    for(int i = 0; i<n;i++){
        double normalized = a[i][i];
        for(int k =0; k<=n;k++){
            a[i][k] /= normalized;
        }
        for(int j = 0;j<n;j++){
            if(i!=j){
                double f = a[j][i];
                for(int k = 0;k<=n;k++){
                    a[j][k] -= f*a[i][k];
                }
            }
        }cout << "After step " << i + 1 << ":" << endl;
            printMat();
    }

    

    cout << "Solution:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(6)
             << a[i][n] / a[i][i] << endl;
    }

return 0;
}