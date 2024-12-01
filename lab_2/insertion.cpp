// #include<bits/stdc++.h>
// using namespace std;

// void insertionSort(vector<long long> &a, long long n){
//     long long i,j,value;
//     for ( i = 1; i < n; i++){
//         value = a[i];
//         j=i-1;
//         while(j>=0 && a[j]>value){
//             a[j+1]=a[j];
//             j=j-1;
//         }
//         a[j+1]=value;
//     }
// }

// int main(){
//     vector<long long> a = {2,3,1,5,6,4};
//     long long steps = 0;
//     insertionSort(a,6,steps);
//     for (int i = 0; i < 6; i++){
//         cout << a[i] << " " ;
//     } 
//     cout << "\nSteps taken: " << steps << endl; 
// }




#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<long long> &a, long long n, long long &steps){
    long long i, j, value;
    for (i = 1; i < n; i++) {
        value = a[i];
        j = i - 1;
        
        steps++;
        
        while (j >= 0 && a[j] > value) {
            steps++; 
            a[j + 1] = a[j];
            steps++;
            j = j - 1;
        }
        a[j + 1] = value; 
        steps++; 
    }
}

int main() {
    vector<long long> a = {2, 3, 1, 5, 6, 4};
    long long steps = 0;
    
    insertionSort(a, 6, steps);
    
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    
    cout << "\nSteps taken: " << steps << endl;
}
