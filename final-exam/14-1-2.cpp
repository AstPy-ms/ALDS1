/*********************************************
 * Linear congruential generators
 *********************************************/
#include <iostream> 
#include <cmath> 
using namespace std;

static const int StudentNum = 19140674; 

int bubbleSort(int A[], int n){

    int flag = 1, counter = 0, j;

    while(flag){
        flag--;
        for(j=n-1;j>0;j--){
            if(A[j] < A[j-1]){
                A[j] += A[j-1];
                A[j-1] = A[j] - A[j-1];
                A[j] = A[j] - A[j-1];
                counter++;
                flag++;
            }
        }
    }

    for(j=0;j<n;j++){
        if(j == 0){
            cout << A[j];
        }else{
            cout << " " << A[j];
        }
    }

    cout << endl << counter << endl;

    return *A;

}

int main(){

    int num = 50;
    int r;
    int a = 1103515245;
    int c = 12345;
    long int m = 2147483648;

    int t = (StudentNum%10)+10;
    int target = 0;

    int rand_num[50] = {0};

    r = StudentNum;
    cout << "Random numbers" << endl;
        for (int i=0; i< num; i++) {
            r = (a * r + c) % m;
            // cout << abs(r%1000) << endl; 
            rand_num[i] = abs(r%1000);
            if(i==t){
                target = abs(r%1000);
            }
        }

    int flag = 1, counter = 0, j;

    while(flag){
        flag--;
        for(j=num-1;j>0;j--){
            if(rand_num[j] < rand_num[j-1]){
                rand_num[j] += rand_num[j-1];
                rand_num[j-1] = rand_num[j] - rand_num[j-1];
                rand_num[j] = rand_num[j] - rand_num[j-1];
                counter++;
                flag++;
            }
        }
    }

    for(j=0;j<num;j++){
        if(j == 0){
            cout << rand_num[j];
        }else{
            cout << " " << rand_num[j];
        }
    }

    cout << endl << counter << endl;
    
    cout << endl;
    cout << "Search Target : " << target << endl;

    for(int i=0;i<num;i++){
        if(rand_num[i] == target){
            cout << "探索回数 = " << i+1 << endl;
            return 0;
        }
    }

    cout << "探したい数字は配列内にはありませんでした。" << endl;
    return 0;

}