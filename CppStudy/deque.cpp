#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// vector : ���� �迭
// [      ]

// list : ���� ���� ����Ʈ
// [] <-> [] <-> [] <-> []

// deque : double-ended queue
// [      ]
// [      ]

int main() {
	// ������ �����̳� (Sequence Container)
	// �����Ͱ� ���� ������� �����Ǵ� ����
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