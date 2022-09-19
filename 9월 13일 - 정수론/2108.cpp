#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[500000]; //수 정렬을 위한 배열. (문제 조건: 수의 개수는 최대 500,000개)

int main() {

    int n;
    vector<int> v; //최빈값을 원소로 갖는 vector 선언

    int count[8001] = {0,}; //최빈값: 원소의 개수를 세는 배열
    //문제 조건: 입력되는 정수의 절댓값은 4000을 넘지 않는다.

    int sum = 0; //산술평균: '모든 수의 합'을 위한 변수
    int max = 0; //최빈값: 가장 많은 원소의 개수를 저장하는 변수

    int mid = 0, cm = 0, range = 0; //중앙값, 최빈값, 범위

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        sum += arr[i]; //산술평균: 합 구하기

        count[arr[i]+4000]++;
    }

    //n개의 수들을 오름차순으로 정렬
    sort(arr, arr + n);



    //산술평균: 모든 값들의 합 / 수의 개수
    float avg = float(sum) / float(n);

    if (avg >= 0)
        avg = int(avg + 0.5);
    else
        avg = int(avg - 0.5);

    //중앙값: 정렬된 배열에서 중앙에 위치하는 값
    mid = arr[n / 2];


    //최빈값 구하는 반복문
    for(int i = 0; i < 8001; i++) {
        if(max < count[i]) {
            max = count[i];
            //가장 많은 원소의 개수를 max에 저장
        }
    }

    //최빈값이 2개 이상일 경우를 위한 반복문
    for(int i = 0; i < 8001; i++) {
        if(count[i] == max) {
            v.push_back(i);
            //최빈값 오름차순 정렬 (최빈값이 2개 이상일 수도 있음)
        }
    }

    // 최빈값이 2개 이상이면, 두번째로 작은 값(v[1]) 출력
    cm = (v.size()>1)? v[1]-4000: v[0]-4000;

    //범위: 최댓값 - 최솟값  (정렬된 배열 이용!)
    range = arr[n - 1] - arr[0];


    cout << int(avg) << '\n'; //형변환 필요!
    cout << mid << '\n';
    cout << cm << '\n';
    cout << range;

    return 0;
}