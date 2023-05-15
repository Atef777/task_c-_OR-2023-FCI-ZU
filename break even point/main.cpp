#include <iostream>

using namespace std;

int main() {
  double fixedCosts, variableCosts, price;

  cout << "Enter the fixed costs: ";
  cin >> fixedCosts;

  cout << "Enter the variable costs: ";
  cin >> variableCosts;

  cout << "Enter the price per unit: ";
  cin >> price;

  double breakEvenPoint = fixedCosts / (price - variableCosts);

  cout << "The break-even point is " << breakEvenPoint << " units." << endl;

  return 0;
}
