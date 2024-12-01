#include<bits/stdc++.h>
using namespace std;

int main(){
    ofstream outFile("random.txt");
    srand(NULL);
    for (int i = 0; i < 2000; i++){
        outFile << rand() << endl;
    }   
    outFile.close();
}