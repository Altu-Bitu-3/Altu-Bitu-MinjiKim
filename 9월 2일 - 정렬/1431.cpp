#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const string &a, const string &b) {
    int a_sum=0, b_sum=0;

    if (a.size() != b.size()){ //a와 b 길이가 다를 경우
        return a.size() < b.size();
    }

    //a와 b 길이가 같을 경우

    //a의 모든 자리수의 합 구하기
    for(int i=0; i<a.size(); i++){
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0){
            a_sum += a[i] - '0';
        }
    }

    //b의 모든 자리수의 합 구하기
    for(int i=0; i<b.size(); i++){
        if (b[i] - '0' <= 9 && b[i] - '0' >= 0){
            b_sum += b[i] - '0';
        }
    }


    //만약 1,2번 조건으로 비교할 수 없을 때(자리수의 합이 같을 때)
    if (a_sum==b_sum){
        return a<b;
    }

    return a_sum<b_sum;


}

int main() {
    int n;
    cin >> n; //기타의 개수 입력

    vector<string> arr(n);

    for (int i=0; i<n; i++){
        cin >> arr[i];  //시리얼 번호 입력
    }

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}