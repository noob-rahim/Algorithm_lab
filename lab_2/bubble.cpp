// #include<bits/stdc++.h>
// using namespace std;

// void bubsort(vector<long long>&a, long long n){
//     bool swp;
//     do{
//         swp=false;
//         for (int i = 0; i < n-1; i++){
//             if(a[i]>a[i+1]){
//                 swap(a[i],a[i+1]);
//                 swp=true;
//             }
//         }
//     }while(swp);
// }

// int main(){
//     vector<long long> a = {2,3,1,5,3,8};
//     bubsort(a,6);
//     for (int i = 0; i < 6; i++){
//         cout << a[i] << " " ;
//     }  
// }



#include<bits/stdc++.h>
using namespace std;

void bubsort(vector<long long>& a, long long n, long long &steps){
    bool swp;
    do {
        swp = false;
        for (int i = 0; i < n - 1; i++) {
            steps++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                steps++;
                swp = true;
            }
        }
    }while (swp);
}

int main() {
    vector<long long> a = {2, 3, 1, 5, 3, 8};
    long long steps = 0;
    bubsort(a, 6, steps);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }cout << "\nSteps taken: " << steps << endl;
}
