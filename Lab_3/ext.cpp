// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// vector<ll>vec;

// long long BinarySearch(vector<ll>vec,ll value,ll low, ll high){
//     if(high < low) return -1;
//     ll mid = (low+high)/2;
//     if(vec[mid]>value)return BinarySearch(vec,value,low,mid-1);
//     else if(vec[mid]<value)return BinarySearch(vec,value,mid+1,high);
//     else return mid;  
// }

// int main(){
//     ifstream inputFile("random.txt");
//     string num;
//     while(getline(inputFile,num)){
//         ll n= stoll(num);
//         vec.push_back(n);
//     }
//     sort(vec.begin(),vec.end());
//     ll n;
//     cout << "Enter any number for search: ";
//     cin >> n;
//     cout << "Index: " << BinarySearch(vec,n,0,vec.size()-1) << endl;
//     inputFile.close();
// }





#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> vec;

long long BinarySearch(vector<ll> &vec, ll value, ll low, ll high) {
    if (high < low) return -1;  // Value not found
    ll mid = (low + high) / 2;
    if (vec[mid] > value) return BinarySearch(vec, value, low, mid - 1);
    else if (vec[mid] < value) return BinarySearch(vec, value, mid + 1, high);
    else return mid;  // Value found
}

int main() {
    ifstream inputFile("random.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string num;
    while (getline(inputFile, num)) {
        ll n = stoll(num);
        vec.push_back(n);
    }
    
    inputFile.close();

    if (vec.size() < 2000) {
        cerr << "Not enough numbers in the file. At least 2000 numbers are required." << endl;
        return 1;
    }

    sort(vec.begin(), vec.end());

    ll n;
    cout << "Enter any number for search: ";
    cin >> n;

    // Now, we pass the indices 0 and vec.size() - 1
    ll index = BinarySearch(vec, n, 0, vec.size() - 1);
    
    if (index != -1) {
        cout << "Index: " << index << endl;
    } else {
        cout << "Number not found." << endl;
    }

    return 0;
}
