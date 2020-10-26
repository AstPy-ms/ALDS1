#include<iostream>
#include<chrono>

#define SIZE 200000

using namespace std;

int main(){

    int n, tmp, max = -1000000001, R[SIZE] = {0};

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> R[i];
        // cout << "R[" << i << "] = " << R[i] << endl;
    }

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now(); 

    for(int i=1; i < n; i++){
        for(int j=0; j < i; j++){
            if(max < R[i] - R[j]){
                max = R[i] - R[j];
            }
        }
    }

    cout << max << endl;

    end = chrono::system_clock::now(); 
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count());
    printf("time %lf[マイクロ秒]\n", time); 

    return  0;

}