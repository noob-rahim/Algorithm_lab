#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

int s=0;
int main(){
    s++;
    int n;
    cin >> n;
    int vec[n];
    vec[0]=0;
    vec[1]=1;
    for (int i = 2; i < n; i++){
        s++;
        vec[i]=vec[i-1]+vec[i-2];
    }
    cout << vec[n] << endl;
    cout << "Step no: " <<  s << endl;
}

