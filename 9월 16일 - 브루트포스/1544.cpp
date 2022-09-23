#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string makeStr(queue<char>& q) {
	string str = "";
	for (int i = 0; i < q.size(); i++) {
		str += q.front();
		q.push(q.front());
		q.pop();
	}

	return str;
}

int main() {

    //단어의 개수
	int N;
	//단어의 개수 입력받기
	cin >> N;

	//단어들을 저장하기 위한 vector
	vector<string> v;

    //단어 한 줄씩 입력받기
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;


		if (v.size() == 0) {
			v.push_back(s);
		}
		else {
			queue<char> q;
			//문자 비교를 위해 queue 사용

			for (int k = 0; k < s.size(); k++) {
				q.push(s[k]);
			}

			bool same = false;
			//문자열이 같은지 확인하는 bool 변수

			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < s.size(); k++) {
					string compstr = makeStr(q);

					if (compstr == v[j]) {
						same = true;
						break;
					}

					q.push(q.front());
					q.pop();
				}

				if (same) {
					break;
					//같은 문자열이 queue에 있으면, vector에 문자열 추가 x
				}
			}

			if (!same) {
				v.push_back(s);
				//같은 문자열이 없으면 vector에 문자열 추가!
			}
		}
	}

	cout << v.size() << "\n";

	return 0;
}