#include <iostream> //입출력 헤더
#include <vector> //벡터 자료형

using namespace std;
const int INF = 1e7; //10^7 = 10^6(각 행렬 성분의 최댓값) * 10(도시의 수(N)의 최댓값)

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬.
int n, ans = INF; //ans: 순회에 필요한 최소 비용을 저장하는 변수. 미리 최댓값으로 초기화

void backtracking(int cnt, int cur_city, int cost) { //재귀함수. cnt: 순회한 도시의 수. cur_city: 현재 있는 도시. cost: (누적된) 비용
    if (cost >= ans) { //총 비용이 저장된 최소 비용보다 크거나 같으면
        return; //리턴
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음. 즉, 모든 도시를 방문한 경우
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //출발 도시로 다시 돌아올 수 있다면,
            ans = min(ans, cost + matrix[cur_city][0]); //적은 비용이 드는 것을 선택
        }
        return; //길이 없다면 리턴
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동. n개의 도시 만큼 반복.
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시인 경우,
            visited[i] = true; //방문을 하고,
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //재귀함수 사용. cost에 matrix[cur_city][i]가누적된다.
            visited[i] = false; //visited[i]를 초기화 해줘야함 (기존 라이브코딩에서 checked 배열 초기화해줬던 것처럼)
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n; //도시의 수 입력받기
    visited.assign(n, false); //도시의 수 만큼 '방문 검사 배열'에 크기 할당.
    matrix.assign(n, vector<int>(n, 0)); //도시의 수 만큼 '비용 행렬'에 크기 할당 후 0으로 초기화.
    for (int i = 0; i < n; i++) { //2차원 배열.
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j]; //maxtirx[i][j]: 도시 i에서 도시 j로 가기 위한 비용.
        }
    }

    //연산
    visited[0] = true; //시작 도시는 이미 방문함. true로 값 바꿔줌.
    backtracking(1, 0, 0); //cnt=1로 시작(매개변수로 넘겨줌)

    //출력
    cout << ans; //정답 출력
    return 0;
}