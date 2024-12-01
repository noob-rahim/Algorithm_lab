#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>vec;

long long BinarySearch(vector<ll>vec,ll value,ll low, ll high){
    if(high < low) return -1;
    ll mid = (low+high)/2;
    if(vec[mid]>value)return BinarySearch(vec,value,low,mid-1);
    else if(vec[mid]<value)return BinarySearch(vec,value,mid+1,high);
    else return mid;  
}

int main(){
    ifstream inputFile("random.txt");
    string num;
    while(getline(inputFile,num)){
        ll n= stoll(num);
        vec.push_back(n);
    }
    sort(vec.begin(),vec.end());
    ll n;
    cout << "Enter any number for search: ";
    cin >> n;
    cout << "Index: " << BinarySearch(vec,n,0,vec.size()-1) << endl;
    inputFile.close();
}