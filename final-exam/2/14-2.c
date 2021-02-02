#include <stdio.h>

int n, A[50], B[50];

int counter = 0;

int solve(int i, int m){
	int res;
	
	if (m == 0){
        counter++;
        printf("Subset: ");
        for(int j=0;j<i;j++){
            if(B[j] == 1){
                printf("%d ", A[j]);
            }
        }
        printf("\n");
        return 1;
    }
	if (i >= n){
        return 0;
    }

    B[i] = 0;
    solve(i+1, m);
    B[i] = 1;
    solve(i+1, m - A[i]);

	/*
    res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
    */
}

int main() {

    // 学修番号と名前の表示
    printf("学修番号 : 19140674\n氏名 : 久下 柾\n");

	int q, M, i;
	FILE *fp;
	
	fp=fopen("data.txt","r");
	fscanf(fp,"%d", &n);
	for (i = 0; i <  n; i++ ){
        fscanf(fp,"%d", &A[i]);
    }
    fclose(fp);
	
	printf("A[0..%d] =",n-1);
	for (i = 0; i <  n; i++ ){
        printf(" %d", A[i]);
    }
    printf("\n");
	
	printf("Input the number of queries q: ");
	scanf("%d", &q);
	
	for (i = 0; i <  q; i++ ) {
		printf("Query %d\n",i+1);
		printf("Input a target value M: ");
		scanf("%d", &M);

        solve(0, M);

        printf("Total number of solutions = %d\n", counter);

        /*
		if ( solve(0, M) ){
            printf("Answer: yes\n");
        }else{
            printf("Answer: no\n");
        }
        */
	}

	return 0;
}