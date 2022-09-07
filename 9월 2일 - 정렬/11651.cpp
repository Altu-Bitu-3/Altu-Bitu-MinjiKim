#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point { //점 구조체
    int x, y;
};

bool cmp(const point &a, const point &b) {
    if (a.y == b.y) { //y좌표가 같으면 x좌표가 증가하는 순서
        return a.x < b.x;
    }
    return a.y < b.y; //y좌표가 같지 않으면 y좌표가 증가하는 순서
}

int main() {
    int n;
    cin >> n; //점의 개수
    vector<point> arr(n);
    for (int i = 0; i < n; i++) { //x좌표, y좌표 입력
        cin >> arr[i].x >> arr[i].y;
    }
    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }
    return 0;
}