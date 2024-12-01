#include<bits/stdc++.h>
#define ll long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define vll vector<ll>
#define loop(n) for(int i=0;i<n;i++)
#define f(a,b,i) for(ll i=a;i<b;i++)
#define rloop(n) for(ll i=n-1;i>=0;i--)
#define rf(a,b,i) for(ll i=a;i>=b;i--)
#define vvll vector<vector<long long>>
#define nl cout<<endl

using namespace std;

//sort(v.begin(),v.end(),[&](pair<ll,ll>x,pair<ll,ll>y){
//});
 
 
 
 
void solve(){
    ofstream inputfile("input.txt");
    srand(time(0));
    loop(1e16){
        inputfile<<rand()%100000+1<<endl;
    }
    inputfile.close();
    return;
} 

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    solve(); 
}