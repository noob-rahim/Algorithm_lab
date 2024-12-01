#include<iostream>
#include<fstream>
using namespace std;

int s=0;
int fib[200000];

int fibon(int n){
    if(fib[n]==-1){
        s++;
        fib[n]=fibon(n-1)+fibon(n-2);
        return fib[n];
    }
    else{
        s++;
        return fib[n]; 
    } 
}

int main(){
    s++;
    int n;
    cin >> n;
    fib[0]=0;
    fib[1]=1;
    for (int i = 2; i < 200000 ; i++){
        fib[i]=-1;
    }
    cout << fibon(n) << endl;
    cout << "Step no: " <<  s << endl;
}

