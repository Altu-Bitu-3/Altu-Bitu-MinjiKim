#include <iostream>
#include <vector> //벡터 사용
#include <algorithm> //reverse() 사용
using namespace std;

const int MAX_ALPHA=26; //알파벳 A~Z 총 26개

vector<int> countAlpha(string input) { //사용된 알파벳 개수 세기위한 함수

    vector<int> alpha(MAX_ALPHA, 0);  //크기: 26, 0으로 초기화.

    for(int i=0; i<input.length(); i++) { //입력받은 문자열 길이만큼 반복
        alpha[input[i]-'A']++;
        // 크기가 26인 배열. 즉, 각 인덱스에 A~Z까지 순서대로 알파벳을 저장.
        // 'A'와의 차를 통해 어떤 알파벳인지를 파악하고, 해당 알파벳의 개수를 0으로 초기화된 인덱스를 하나씩 증가시키는 방식으로 사용된 알파벳 개수를 센다.
        // ex) 0번째 인덱스: 'A'의 개수 저장. 25번째 인덱스: 'Z'의 개수 저장.
    }

    return alpha; //벡터 리턴
}

string makePalindrome(string input) { //문자열을 팰린드롬으로 변환하는 함수

    vector<int> alpha=countAlpha(input); //입력된 문자열의 알파벳 개수를 세서 alpha 벡터에 저장
    string center="", str="", ans;   //center: 가운데에 위치할 문자 저장을 위한 변수, str: 앞뒤로 사용할 문자열 저장을 위한 변수, ans: 팰린드롬으로 변환된 문자열 저장을 위한 변수

    for(int i=0; i<MAX_ALPHA; i++) { //알파벳 개수(총 26개)만큼 반복.

        if(alpha[i]%2) { //alpha[i]%2: 알파를 2로 나눴을때의 나머지가 1이라면, 즉 홀수라면,
            if(center.length()) { //가운데에 위치할 문자가 1개 이라면 (즉 홀수인 알파벳이 2개 이상이라면)
                return "I'm Sorry Hansoo"; //해당 문자열을 반환. 팰린드롬화 불가능!
            }

            //center에 저장된 문자가 아직 존재하지 않는다면, center 변수에 문자를 저장 (즉, 가운데에 위치할 문자가 되는 것)
            center=(char)(i+'A');
        }

        for(int j=0; j<alpha[i]/2; j++) { //사용된 알파벳의 개수/2 만큼 반복
            str+=(char)(i+'A');
            //str(앞 뒤로 사용할 문자열)에 알파벳 순으로 '사용된 알파벳의 개수/2' 만큼 저장
        }
    }

    ans=str+center; //ans: 팰른드롬화를 완료하여 출력할 문자열. 문자열+가운데 문자열 저장
    reverse(str.begin(), str.end()); //reverse() 함수를 사용하여 str에 저장된 문자열 reverse하기
    ans+=str; //문자열+ 가운데 문자열 + 앞의 문자열 reverse한 문자열 = 팰린드롬

    return ans; //팰린드롬된 문자열 반환
}

int main() {
    string input, ans;   //input: 문자열을 입력 받기 위한 변수, ans: 입력받은 문자열을 팰린드롬으로 변환한 후 해당 문자열을 저장하기 위한 변수
    cin>>input; //문자열 입력 받기

    ans=makePalindrome(input); //입력받은 문자열을 팰린드롬으로 변환하기
    cout<<ans; //변환된 문자열을 출력하기
    return 0;
}