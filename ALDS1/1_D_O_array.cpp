#include<iostream>
#include<chrono>

#define SIZE 200000

using namespace std;

int main(){

    int n, max = -1000000001, min, tmp, R[SIZE] = {0};

    cin >> n;
    for(int i=0 ; i < n ; i++){
        cin >> R[i];
    }
    min = R[0];

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now(); 

    for(int i=1; i < n; i++){
        // cin >> tmp;
        // cout << "R[" << i+1 << "] = " << tmp << endl; 
        if(max < R[i] - min){
            max = R[i] - min;
        }
        if(min > R[i]){
            min = R[i];
        }
    }

    cout << max << endl;

    end = chrono::system_clock::now(); 
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count());
    printf("time %lf[マイクロ秒]\n", time); 

    return  0;

}