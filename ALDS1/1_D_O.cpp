#include<iostream>

using namespace std;

int main(){

    int n, max = -1000000001, min, tmp;

    cin >> n;
    cin >> min;
    // cout << "R[0] = " << min << endl;

    for(int i=0; i < n-1; i++){
        cin >> tmp;
        // cout << "R[" << i+1 << "] = " << tmp << endl; 
        if(max < tmp - min){
            max = tmp - min;
        }
        if(min > tmp){
            min = tmp;
        }
    }

    cout << max << endl;

    return  0;

}