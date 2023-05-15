#include <iostream>
#include <vector>
using namespace std;
// Function to find the pivot element
int findPivot(vector<vector<double>>& tableau, int n, int m)
{
    int pivotRow = -1;
    double minRatio = 0;
    for (int i = 1; i < n; i++)
    {
        if (tableau[i][m - 1] < 0)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (tableau[i][j] < 0)
                {
                    double ratio = -tableau[i][m - 1] / tableau[i][j];
                    if (pivotRow == -1 || ratio < minRatio)
                    {
                        minRatio = ratio;
                        pivotRow = i;
                    }
                }
            }
        }
    }
    return pivotRow;
}
// Function to perform the simplex algorithm
void simplex(vector<vector<double>>& tableau, int n, int m, bool maximize)
{
    while (true)
    {
        int pivotColumn = -1;
        if (maximize)
        {
            double maxCoefficient = 0;
            for (int j = 0; j < m - 1; j++)
            {
                if (tableau[0][j] > maxCoefficient)
                {
                    maxCoefficient = tableau[0][j];
                    pivotColumn = j;
                }
            }
        }
        else
        {
            double minCoefficient = 0;
            for (int j = 0; j < m - 1; j++)
            {
                if (tableau[0][j] < minCoefficient)
                {
                    minCoefficient = tableau[0][j];
                    pivotColumn = j;
                }
            }
        }
        if (pivotColumn == -1)
        {
            break;
        }
        int pivotRow = findPivot(tableau, n, m);
        double pivotElement = tableau[pivotRow][pivotColumn];
        for (int j = 0; j < m; j++)
        {
            tableau[pivotRow][j] /= pivotElement;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != pivotRow)
            {
                double factor = tableau[i][pivotColumn];
                for (int j = 0; j < m; j++)
                {
                    tableau[i][j] -= factor * tableau[pivotRow][j];
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cout << "Enter the number of variables: ";
    cin >> n;
    cout << "Enter the number of constraints: ";
    cin >> m;
    vector<vector<double>> tableau(n + 1, vector<double>(m + n + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m + n + 1; j++)
        {
            if (j == n + i)
            {
                tableau[i][j] = 1;
            }
            else if (j > n && j < n + m + 1)
            {
                cout << "Enter the coefficient of variable x" << j - n << " in constraint " << i + 1 << ": ";
                cin >> tableau[i][j];
            }
            else if (j == m + n)
            {
                if (i == 0)
                {
                    cout << "Enter the coefficient of the objective function (maximization): ";
                }
                else
                {
                    cout << "Enter the constant term in constraint " << i << ": ";
                }
                cin >> tableau[i][j];
                if (i == 0 && tableau[i][j] < 0)
                {
                    for (int k = 0; k < m + n + 1; k++)
                    {
                        tableau[i][k] = -tableau[i][k];
                    }
                }
            }
            else
            {
                tableau[i][j] = 0;
            }
        }
    }
    simplex(tableau, n + 1, m + n + 1, true);
    cout << "The optimal solution is: " << tableau[0][m + n] << endl;
    return 0;
}
