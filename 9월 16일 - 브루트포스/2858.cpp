//입출력을 위한 선언
#include <iostream>
using namespace std;

pair<int, int> length(int r, int b) {
    int area = r + b; //타일의 넓이= 빨간 타일 개수 + 갈색 타일 개수 (타일은 1x1 크기이기 때문)
    for (int i = area; i > 0; i--) { //높이의 초기값을 넓이 (즉 r+b)로 설정하고, 이를 하나씩 줄여나가며 확인하는 반복문.
       if (area % i != 0) { //넓이(area)를 i(높이)로 나눈 값의 나머지가 0이 아니면, 즉 i로 나누어떨어지지 않는다면, 이는 직사각형이 아니라는 뜻
            continue; //직사각형이 아니라면 넘어간다.
        }
        //area가 i로 나누어떨어진다면, 직사각형이라는 의미이므로,
        int w = area / i; // area=width(w)*height(l). 즉, i는 높이의 값 height(l).
        if (r == ((i + w) * 2 - 4)) { // '빨간 타일 r = 가장자리에 있는 테두리 타일의 개수 (높이+너비*2-4(겹치는부분))' 조건을 만족한다면,
            return make_pair(i, w); //높이, 너비 pair를 만들어서 리턴
        }
    }
}

int main() { //메인 함수
    int r, b; //r: 빨간 타일 개수, b: 갈색 타일 개수

    //각 색깔별 타일 개수 입력받기
    cin >> r >> b;

    //연산 값을 pair에 저장
    pair<int, int> result = length(r, b);

    //위의 연산으로 인해 리턴된 pair를 출력
    cout << result.first << ' ' << result.second << '\n'; //높이와 너비 출력
    return 0;
}