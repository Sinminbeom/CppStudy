#include <iostream>
#include <map>
using namespace std;

class Player {
public:
	Player() : _playerId(0) {}
	Player(int playerId) : _playerId(playerId) {}
public:
	int _playerId;
};

class Node {
public:
	Node* _left;
	Node* _right;
	pair<int, Player*> _data;
};

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200));

	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5���� ����
	for (int i = 0; i < 50000; i++) {
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	unsigned int count = 0;
	count = m.erase(10000);
	count = m.erase(10000);

	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end()) {
		cout << "ã��" << endl;
	}
	else {
		cout << "��ã��" << endl;
	}

	// map ��ȸ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		pair<const int, int>& p = *it;
		int key = it->first;
		int value = it->second;

		cout << key << " " << value << endl;

	}

	// ������ �߰� ������ ����
	map<int, int>::iterator it = m.find(10000);
	if (it != m.end()) {
		it->second = 200;
	}
	else {
		m.insert(make_pair(10000, 10000));
	}

	// ������ �߰� ������ ���� v2
	m[5] = 100;

	m.clear();

	// [] ������ ����
	// �������� �ʴ��� (key/value) ������ �����Ͱ� �߰��ȴ�
	for (int i = 0; i < 10; i++) {
		cout << m[i] << endl;
	}
	return 0;
}