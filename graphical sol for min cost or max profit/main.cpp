#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define the data point structure
struct DataPoint
{
    int x;
    int y;
    int cost;
};
// Define a function to compare two data points based on their cost
bool compareByCost(DataPoint a, DataPoint b)
{
    return a.cost < b.cost;
}
// Define a function to find the minimum cost or maximum profit using a graphical solution
int findMinCostOrMaxProfit(vector<DataPoint> dataPoints)
{
    // Sort the data points by their costs in non-decreasing order
    sort(dataPoints.begin(), dataPoints.end(), compareByCost);
    // Initialize the minimum cost or maximum profit to zero
    int minCostOrMaxProfit = 0;
    // Initialize the current x and y coordinates to the first data point
    int currentX = dataPoints[0].x;
    int currentY = dataPoints[0].y;
    // Traverse the remaining data points and calculate the minimum cost or maximum profit
    for (int i = 1; i < dataPoints.size(); i++)
    {
        // Calculate the cost of moving from the current data point to the next data point
        int cost = abs(currentX - dataPoints[i].x) + abs(currentY - dataPoints[i].y);
        // Update the minimum cost or maximum profit
        if (dataPoints[0].cost < 0)
        {
            minCostOrMaxProfit -= cost * dataPoints[i].cost;
        }
        else
        {
            minCostOrMaxProfit += cost * dataPoints[i].cost;
        }
        // Update the current x and y coordinates
        currentX = dataPoints[i].x;
        currentY = dataPoints[i].y;
    }
    return minCostOrMaxProfit;
}
int main()
{
    // Create a vector of data points
    vector<DataPoint> dataPoints =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
    };
    // Find the minimum cost or maximum profit using a graphical solution
    int result = findMinCostOrMaxProfit(dataPoints);
    // Print the result
    cout << "The minimum cost or maximum profit is: " << result << endl;
    return 0;
}
