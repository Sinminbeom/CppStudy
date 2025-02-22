#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Iterator {
public:
	Iterator() {

	}

	Iterator(T* ptr) : _ptr(ptr) {

	}

	Iterator& operator++() {
		_ptr++;
		return *this;
	}

	Iterator operator++(int) {
		Iterator iter = *this;
		_ptr++;
		return iter;
	}

	bool operator==(const Iterator& right) {
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right) {
		//return !(*this == right);
		return _ptr != right._ptr;
	}

	T& operator*() {
		return *_ptr;
	}

	Iterator operator+(const int count) {
		Iterator iter = *this;
		iter._ptr += count;
		return iter;
	}
public:
	T* _ptr;
};

template<typename T>
class Vector {
public:
	Vector() : _size(0), _capacity(0), _data(nullptr) {

	}

	~Vector() {
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value) {
		if (_size == _capacity) {
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;
			reserve(newCapacity);
		}

		_data[_size] = value;

		_size++;
	}

	void reserve(int capacity) {
		_capacity = capacity;

		T* newData = new T[capacity];

		for (int i = 0; i < _size; i++) {
			newData[i] = _data[i];
		}

		delete[] _data;
		_data = newData;
	}

	T& operator[](const int index) {
		return _data[index];
	}

	int size() const { return _size; }
	int capacity() const { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin() {
		return iterator(&_data[0]);
	}

	iterator end() {
		return begin() + _size;
	}

public:
	int _size;
	int _capacity;
	T* _data;
};

/*
int main() {
	Vector<int> v;

	//v.reserve(100);

	for (int i = 0; i < 100; i++) {
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
*/