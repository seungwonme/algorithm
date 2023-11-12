#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int	isDigit(char c)
{
	if ('0' <= c && c <= '9')
		return 1;
	return 0;
}

void	pushArrInDQ(deque<int>& DQ, string arr)
{
	for (size_t i = 0; i < arr.length(); i++)
	{
		int num = 0;

		if (isDigit(arr[i]))
		{
			while (isDigit(arr[i]))
			{
				num = num * 10 + arr[i] - '0';
				++i;
			}
			DQ.push_back(num);
		}
	}
}

void	printDQ(deque<int>& DQ, bool isReverse)
{
	deque<int>::iterator last = DQ.end();
	if (DQ.size() > 0) --last;
	cout << '[';
	if (isReverse && DQ.size() > 0)
	{
		for (deque<int>::iterator it = last; it >= DQ.begin(); --it)
		{
			cout << *it;
			if (it != DQ.begin())
				cout << ',';
		}
	}
	else if (!isReverse && DQ.size() > 0)
	{
		for (deque<int>::iterator it = DQ.begin(); it < DQ.end(); ++it)
		{
			cout << *it;
			if (it != last)
				cout << ',';
		}
	}
	cout << "]\n";
}

int	main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;

	for (int i = 0; i < T; i++)
	{
		string p; cin >> p; // 함수
		int n; cin >> n; // 배열 안의 숫자 개수
		string arr; // 배열
		bool isReverse = false; // 배열을 뒤집었는 지 여부
		bool isError = false;

		// std::cin.ignore(); // cin 버퍼 비우기
		// getline(cin, arr);
		cin >> arr;

		deque<int> DQ;
		pushArrInDQ(DQ, arr); // 덱에 배열을 넣음

		for (size_t j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R')
				isReverse = !isReverse;
			if (p[j] == 'D')
			{
				// 배열이 뒤집혔을 때
				if (isReverse)
				{
					if (DQ.empty())
					{
						isError = true;
						break;
					}
					DQ.pop_back();
				}
				else
				{
					if (DQ.empty())
					{
						isError = true;
						break;
					}
					DQ.pop_front();
				}
			}
		}
		if (isError) cout << "error\n";
		else printDQ(DQ, isReverse);
	}

	return 0;
}

/*
시간 제한	메모리 제한
1 초	256 MB
문제
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다.
배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다.
예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

예제 입력 1
4
RDD						// 수행할 함수 P (R: 뒤집기, D: 버리기)
4							// 배열에 들어있는 수의 개수
[1,2,3,4]			// 배열에 들어있는 정수
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
예제 출력 1
[2,1]
error					// 배열이 비어있는데 D를 사용한 경우
[1,2,3,5,8]
error
*/
