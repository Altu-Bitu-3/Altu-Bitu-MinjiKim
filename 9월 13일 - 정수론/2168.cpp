#include<iostream>

using namespace std;

//유클리드 호제법을 이용하여 최대공약수를 구하는 함수
int gcd(int a, int b) { //유클리드 호제법: 나누는 수와 나머지로 나누는 과정을 되풀이
	if (b == 0) { //나머지가 0일때, 최대공약수가 나오게 됨
		return a; //최대 공약수 리턴
	}
	return gcd(b, a % b); //b: 나누는 수, a:나눠지는 수, a%b: 나머지. 나누는 수와 나머지로 나누는 과정을 되풀이
}

int main() {
	int n, m; //입력을 받기 위한 정수 선언. n: 가로, m: 세로
	cin >> n >> m; //정수 2개 입력받기
	cout << n + m - gcd(n, m); //대각선이 지나는 타일 수 n+m-gcd(n,m) 출력
	//gcd=1인 경우도 위와 똑같이 해당되어서 따로 예외사항 없음.
}