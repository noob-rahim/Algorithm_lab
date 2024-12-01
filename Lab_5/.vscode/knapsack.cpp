#include <bits/stdc++.h>
using namespace std;

double greedyKnapsack(int m,int n,vector<int>& weights, vector<int>& profits) {
    vector<pair<double, pair<int, int>>>items;
    vector<double> x(n, 0.0);
    for (int i = 0; i < n; i++) {
        double ratio = (double)profits[i] /weights[i];
        items.push_back({ratio, {weights[i],profits[i]}});
    }
    sort(items.begin(), items.end(),greater<>());
    int U = m;
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        int weight = items[i].second.first;
        int profit = items[i].second.second;
        if (weight > U) {
            x[i] = (double)U / weight;
            totalProfit += x[i] * profit;
            break;
        } else {
            x[i] = 1.0;
            U -= weight;
            totalProfit += profit;
        }
    }   
    cout << "Solution(fraction of each item taken): ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    return totalProfit;
}
int main() {
    int m,n;
    vector<int> weights;
    vector<int> profits;
    ifstream file("knapsackfile.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    file >> m;
    file>>n;
    string line;
    getline(file, line);
    getline(file, line);
    istringstream issWeights(line);
    int weight;
    while (issWeights >> weight) {
        weights.push_back(weight);
    }
    getline(file, line);
    istringstream issProfits(line);
    int profit;
    while (issProfits >> profit) {
        profits.push_back(profit);
    }
    file.close();
    double maxProfit = greedyKnapsack(m,n,
    weights, profits);
    cout << "Maximum profit: " << maxProfit<< endl;
    return 0;
}
