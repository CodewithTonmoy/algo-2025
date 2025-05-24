#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, vector<int>& selectedItems) {
    int n = weights.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

 
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1); 
            w -= weights[i - 1];
        }
    }

    return dp[n][W]; /
}

int main() {
   
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    vector<int> selectedItems;
    int maxValue = knapsack(capacity, weights, values, selectedItems);

    
    cout << "Maximum value: " << maxValue << endl;
    cout << "Selected item indices (0-based): ";
    for (int i = selectedItems.size() - 1; i >= 0; i--)
        cout << selectedItems[i] << " ";
    cout << endl;

    return 0;
}
