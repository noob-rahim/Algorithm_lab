#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("./testcase.txt","w", stdout);
    srand(time(0));
    set<int> a;
    for (int i=0; a.size()<10; i++){
        int x=50+(rand()%44);
        a.insert(x);
    }
    sort(a.begin(), a.end());
    for (auto it=a.begin(); it!=a.end(); it++){
        cout<<*it<<endl;
    }
}