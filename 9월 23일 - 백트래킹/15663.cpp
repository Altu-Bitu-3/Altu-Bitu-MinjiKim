#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

const int SIZE = 8;

int num[SIZE], arr[SIZE];
bool check[SIZE+1];

void backtracking(int cnt) { //cnt: 수열 인덱스
    if (cnt == m) { //m개 수 고름 (기저 조건)
        for (int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int value=0; // value: 이전 선택값.

    for (int i = 0; i < n; i++) { //i: 고르려는 수
        if (!check[i] && arr[i]!=value){
            num[cnt] = arr[i];
            value = num[cnt]; //이전 선택 값을 저장!
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            check[i] = false;
        }
    }
}

int main() {
    //입력
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];}

    sort(arr, arr+n); //입력된 수 사전순으로 증가하는 순서대로 정렬 (오름차순)

    //연산
    backtracking(0);
}