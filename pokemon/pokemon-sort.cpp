/* 名前がないやつがあるので絶対にバグる */

/*  参考サイト
- csvの読み込み http://scitex.hateblo.jp/entry/2013/02/23/231640
- csvへ書き込み https://qiita.com/shirosuke_93/items/d5d068bb15c8e8817c34
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define NAME 1  // 名前は2列目の要素なので、配列操作用に 1 として定義しておく。

using namespace std;


// csvファイルに書き込む関数

void printArray(vector<vector<string>> list, int n){

    // 書き込むファイル
    ofstream output_csv("./Result.csv");

    // 2次元配列っぽくやるだけ
    for(unsigned int i = 0; i < list.size(); ++i){
        for(unsigned int j = 0; j < list[i].size(); ++j){
            output_csv << list[i][j] << ",";
        }
        output_csv << endl;
    }

}


// 挿入ソート関数

void insertionSort (vector<vector<string>> A, int n) {

    int i, j;
    string v;

    for (i=1;i<n;i++) {
        v = A[i][NAME];
        j = i - 1;

        while (j >= 0 && A[j][NAME] > v){
            swap(A[j+1], A[j]);
            j--;
        }
        A[j+1][NAME] = v;
    }

    printArray(A, n);

}


int main(){

    ifstream file("./pokemon.csv");  // 読み込むcsv
    vector<vector<string>> data;  // csvファイルをvectorに整理する用。実質的な2次元配列。
    string str;  // csvファイルの1行まるまる読み込む用のtmp str
    int p;
    int flg = 0;

    while(getline(file, str)){

        //コメント箇所は除く
        // nposはstring::findで値が見つからなかった場合に返す値として定義されているらしい。
        if( (p = str.find("//")) != str.npos ) continue;
        vector<string> inner;

        //コンマがあるかを探し、そこまでをdataに格納
        while( (p = str.find(",")) != str.npos){
            
            // 文字列の指定位置から最後まで、もしくは、指定位置から指定した数の文字列を取得するらしい。
            inner.push_back(str.substr(0, p));

            //strの中身は", "の2文字を飛ばす
            str = str.substr(p+1);
        }

        // flgで分けることで、1行目の説明を取らずに済む。
        if(flg){
            // pythonでいうとこのappend
            inner.push_back(str);
            data.push_back(inner);
        }

        flg++;
    }

    insertionSort(data, data.size());

    return 0;
}
