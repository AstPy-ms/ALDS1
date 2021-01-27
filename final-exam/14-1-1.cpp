/*********************************************
 * Linear congruential generators
 *********************************************/
#include <iostream> 
#include <cmath> 
using namespace std;

static const int StudentNum = 19140674; 

void bubbleSort(int A[], int n){

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

    bubbleSort(rand_num, num);
    
    cout << endl;
    cout << "Search Target : " << target << endl;

    return 0; 
}