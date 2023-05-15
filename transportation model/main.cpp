#include <iostream>
#include <vector>
using namespace std;
const int N = 3; // number of supply nodes
const int M = 3; // number of demand nodes
// supply and demand values
int supply[N] = {10, 20, 30};
int demand[M] = {15, 10, 25};
// cost matrix
int cost[N][M] =
{
    {2, 3, 4},
    {5, 4, 3},
    {7, 8, 6}
};
int main()
{
    // create an empty 2D matrix of size N x M
    vector<vector<int>> allocation(N, vector<int>(M));
    // initialize the total cost to 0
    int totalCost = 0;
    // loop through each cell in the matrix and assign the minimum cost
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // calculate the minimum of supply[i] and demand[j]
            int amount = min(supply[i], demand[j]);
            // assign the amount to the current cell
            allocation[i][j] = amount;
            // reduce the supply and demand values
            supply[i] -= amount;
            demand[j] -= amount;
            // calculate the cost and add it to the total cost
            totalCost += cost[i][j] * amount;
        }
    }
    // print the allocation matrix and total cost
    cout << "Allocation Matrix: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total Cost: " << totalCost << endl;
    return 0;
}
