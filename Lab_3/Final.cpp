#include <bits/stdc++.h>
using namespace std;

int iterativeLinearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int recursiveLinearSearch(const vector<int>& arr, int target, int index) {
    if (index >= arr.size()) return -1;
    if (arr[index] == target) return index;
    return recursiveLinearSearch(arr, target, index + 1);
}

int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return recursiveBinarySearch(arr, target, mid + 1, high);
    else return recursiveBinarySearch(arr, target, low, mid - 1);
}

void createSortedData(int size) {
    ofstream file("data_" + to_string(size) + ".txt");
    for (int i = 0; i < size; i++) {
        file << i << endl;
    }
}

vector<int> loadData(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}

int main() {
    vector<int> sizes = {1000, 2000, 3000, 4000, 5000, 10000, 15000, 20000, 25000, 30000};
    const int repeatCount = 10000;
    
    cout << left << setw(35) << "Search Type"<< setw(15) << "Data Size"<< setw(20) << "Avg Time (µs)" << endl;
    cout << string(75, '=') << endl;

    for (int size : sizes) {
        string filename = "data_" + to_string(size) + ".txt";
        createSortedData(size);
        vector<int> data = loadData(filename);

        int target = size - size / 4;

        // Iterative Linear Search
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < repeatCount; ++i) {
            iterativeLinearSearch(data, target);
        }
        auto end = chrono::high_resolution_clock::now();
        auto iterativeLinearTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << left << setw(35) << "Linear Search (Iterative)"<< setw(15) << size<< setw(20) << iterativeLinearTime / repeatCount << endl;

        // Recursive Linear Search
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < repeatCount; ++i) {
            recursiveLinearSearch(data, target, 0);
        }
        end = chrono::high_resolution_clock::now();
        auto recursiveLinearTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << left << setw(35) << "Linear Search (Recursive)"<< setw(15) << size << setw(20) << recursiveLinearTime / repeatCount << endl;

        // Iterative Binary Search
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < repeatCount; ++i) {
            iterativeBinarySearch(data, target);
        }
        end = chrono::high_resolution_clock::now();
        auto iterativeBinaryTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << left << setw(35) << "Binary Search (Iterative)" << setw(15) << size << setw(20) << iterativeBinaryTime / repeatCount << endl;

        // Recursive Binary Search
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < repeatCount; ++i) {
            recursiveBinarySearch(data, target, 0, data.size() - 1);
        }
        end = chrono::high_resolution_clock::now();
        auto recursiveBinaryTime = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << left << setw(35) << "Binary Search (Recursive)"<< setw(15) << size << setw(20) << recursiveBinaryTime / repeatCount << endl;

        cout << string(75, '-') << endl;
    } return 0;}
