#include <iostream>
#include <string>

using namespace std;

//유클리드 호제법
int gcd(int a,int  b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(void)
{
	string str, tmp;
    cin >> str;
    int n, m, g;

    for (int i=0; i<str.size(); i++){
        if (str[i]==':'){
            //n
            tmp=str.substr(0,i); //임시로 문자 저장할 tmp 변수
            n=stoi(tmp);


            //m
            tmp=str.substr(i+1, str.length());
            m=stoi(tmp);

            break;
        }
    }

	if (n > m)
		g = gcd(n, m);
	else
		g = gcd(n, m);

	cout << n / g << ":" << m / g;
}


