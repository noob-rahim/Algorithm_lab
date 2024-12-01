#include<bits/stdc++.h>
using namespace std;

bool readInputFromFile(const string &filename, int &numJobs, vector<int> &weights, vector<int> &profits) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return false;
    }

    string line;

    
    getline(inputFile, line);
    stringstream(line) >> numJobs;

   
    getline(inputFile, line);
    stringstream weightsStream(line);
    int weight;
    while (weightsStream >> weight) {
        weights.push_back(weight);
    }

   
    getline(inputFile, line);
    stringstream profitsStream(line);
    int profit;
    while (profitsStream >> profit) {
        profits.push_back(profit);
    }

    inputFile.close();
    return true;
}
