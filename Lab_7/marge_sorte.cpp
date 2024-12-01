#include <bits/stdc++.h>
using namespace std;

vector<long long> b;

void mergesort(vector<long long> &v, long long low, long long mid, long long high, long long &stepscount){
    long long i = low, k = low, j = mid + 1;
    stepscount++;
    while (i <= mid && j <= high) {
        stepscount++;
        if (v[i] < v[j]) {
            b[k] = v[i];
            i++;
        } else {
            b[k] = v[j];
            j++;
        }
        stepscount++;
        k++;
    }
    if (i > mid) {
        while (j <= high) {
            b[k] = v[j];
            j++;
            k++;
            stepscount++;
        }
    } else {
        while (i <= mid) {
            b[k] = v[i];
            i++;
            k++;
            stepscount++;
        }
    }
    for (long long i = low; i <= high; i++) {
        v[i] = b[i];
        stepscount++;
    }
}

void merge(vector<long long> &v, long long low, long long high, long long &stepscount) {
    if (low < high) {
        long long mid = (low + high) / 2;
        merge(v, low, mid, stepscount);
        merge(v, mid + 1, high, stepscount);
        mergesort(v, low, mid, high, stepscount);
    }
}

void solve() {
    vector<long long> test(10);
    ifstream testcases("testcase.txt");
    long long value;
    for (int i = 0; i < 10; i++) {
        testcases >> value;
        test[i] = value;
    }
    testcases.close();
    
    ifstream inputfile("input.txt");
    vector<vector<long long>> testcase;
    for (int i = 0; i < 10; i++) {
        vector<long long> v;
        long long a = test[i];
        long long val;
        for (long long j = 0; j < a; j++) {
            inputfile >> val;
            v.push_back(val);
        }
        testcase.push_back(v);
    }
    inputfile.close();
    
    ofstream outputfile("output.txt");
    outputfile << "No\tNo of elements\t\tWorst case Steps\tBest case Steps\tAverage case Steps\n";
    for (int i = 0; i < 10; i++) {
        long long stepscount_avg = 0, stepscount_best = 0, stepscount_worst = 0;
        b.resize(testcase[i].size());
        
        vector<long long> best = testcase[i];
        vector<long long> worst = testcase[i];
        
        sort(best.begin(), best.end());
        merge(best, 0, best.size() - 1, stepscount_best);
        
        sort(worst.begin(), worst.end(), greater<long long>());
        merge(worst, 0, worst.size() - 1, stepscount_worst);
        
        merge(testcase[i], 0, testcase[i].size() - 1, stepscount_avg);
        
        outputfile << i + 1 << "\t" << testcase[i].size() << "\t\t" << stepscount_worst << "\t\t\t" << stepscount_best << "\t\t" << stepscount_avg << endl;
    }
    outputfile.close();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
