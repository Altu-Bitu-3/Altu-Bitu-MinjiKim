#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
hint: 결과에서부터 역순으로 생각하기!
*/


int main() {

	int n; //N장
    cin >> n; //입력받기

	vector<int> arr(n); //수열 A
    deque<int> deq;

    int card = 1;

    //입력받기
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


    //i번째로 카드를 내려놓을 때 x번 기술 사용. 기술 순서 역순으로 생각하기!
    //x=1: 맨 뒤에 push
    //x=2: 맨 뒤에서 두번째에 push
    //x=3: 맨 앞에 push

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 1) {
            //맨 뒤에 push
			deq.push_back(card);
		}
        else if (arr[i] == 2) {
			int end = deq.back();
			deq.pop_back();
            //맨 뒤에서 두번째에 push
			deq.push_back(card);
			deq.push_back(end);
		}
        else if (arr[i] == 3) {
            //맨 앞에 push
			deq.push_front(card);
		}

        //순서대로 1,2, ..., N.
		card++;
	}

	//출력
	for (int i = n-1; i >=0; i--) {
        cout << deq[i] << ' ';
    }
	cout << '\n';

}