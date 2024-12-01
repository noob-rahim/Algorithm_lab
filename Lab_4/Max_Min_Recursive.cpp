// max min iterrative
#include <bits/stdc++.h>
using namespace std;

void Max_Min(const vector<int>& a, int n, int &max, int &min) {
    if (n <= 0) return; 
    max = a[0];
    min = a[0]; 
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        else if (a[i] < min) min = a[i];
    }
}

int main() {
    // int a[7] = {35, 82, 65, 15, 82, 50, 7};
    int t;
    cin >> t;
    vector<int>a(t);
    for (int i = 0; i < t; i++){
        cin >> a[i];
    }
    
    int max, min;

    Max_Min(a, t, max, min); 

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    return 0;
}




// max min recursive
#include <bits/stdc++.h>
using namespace std;

vector<int>a;
int i,j;

void Max_Min(const vector<int>& a, int n, int &max, int &min){

}