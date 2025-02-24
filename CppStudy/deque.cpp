#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// vector : 동적 배열
// [      ]

// list : 이중 연결 리스트
// [] <-> [] <-> [] <-> []

// deque : double-ended queue
// [      ]
// [      ]

int main() {
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector, list, deque

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);
	

	return 0;
}