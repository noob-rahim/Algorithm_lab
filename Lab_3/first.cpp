#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>v;

long long linearSearch(vector<ll>v,ll n){
    ll i;
    for (i = 0; i < v.size(); i++){
       if(v[i]==n)return i+1;
    }      
}

int main(){
    ifstream inputFile("random.txt");
    string number;
    while(getline(inputFile,number)){
        ll n= stoll(number);
        v.push_back(n);
    }
    ll n;
    cout << "Enter any number for search: ";
    cin >> n;
    cout << "Index: " << linearSearch(v,n) << endl;
    inputFile.close();
}