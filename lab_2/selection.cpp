// #include<bits/stdc++.h>
// using namespace std;

// void selectionsort (vector<long long> &a, long long n){
//     long long min,temp,i,j;
//     for ( i = 0; i < n-1; i++){
//         min = i;
//         for (j = i+1; j < n; j++){
//             if(a[j]<a[min])min=j;
//         }
//         swap(a[i],a[min]);
//     }   
// }

// int main(){
//     vector<long long> a= {3,6,1,5,2,4};
//     selectionsort(a,6);
//     for (int i = 0; i < 6; i++){
//         cout << a[i] << " ";
//     }
    
// }




#include<bits/stdc++.h>
using namespace std;

void selectionsort (vector<long long> &a, long long n, long long &steps){
    long long min, temp, i, j;
    for ( i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            steps++; 
            if(a[j]<a[min]) 
                min=j;
        }
        if(min != i){
            swap(a[i],a[min]);
            steps++; 
        }
    }   
}

int main(){
    vector<long long> a= {3,6,1,5,2,4};
    long long steps = 0;
    selectionsort(a,6,steps);
    for (int i = 0; i < 6; i++){
        cout << a[i] << " ";
    }
    cout << "\nSteps taken: " << steps << endl;
}
