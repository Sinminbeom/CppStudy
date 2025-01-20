#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#pragma region 함수이름
// 나쁜 네이밍의 예
int Calculate(int a, int b, int x) {
    int r = a + b * x;
    return r;
}

// 좋은 네이밍의 예
int CalculateTotalPrice(int base_price, int quantity, int discount_percentage) {
    int total_price = base_price * quantity - (base_price * quantity * discount_percentage / 100);
    return total_price;
}
#pragma endregion


#pragma region 상수이름
const int kDaysInAWeek = 7;

void ComputeFoo(std::string suffix) {
    const std::string prefix = "prefix";
}

#pragma endregion

#pragma region 변수이름

template <typename T>
class Pool {
private:
    std::vector<T*> pool_;
};


std::string table_name;

class TableInfo {
private:
    std::string table_name_;
    static Pool<TableInfo>* pool_;
};

struct UrlTableProperties {
    std::string name;
    int num_entries;
    static Pool<UrlTableProperties>* pool;
};


#pragma endregion

#pragma region 타입이름

// classes and structs
class UrlTable {};
class UrlTableTester {};
//struct UrlTableProperties {};

// typedef
typedef std::unordered_map<UrlTableProperties*, std::string> PropertiesMap;

// using aliases
using PropertiesMap = std::unordered_map<UrlTableProperties*, std::string>;

// enums
enum class UrlTableError {};

#pragma endregion

#pragma region 타입이름

//class UrlTable {};
//class UrlTableTester {};
//struct UrlTableProperties {};

#pragma endregion

class ClassB;

class ClassA {
private:
    int value_a_;

public:
    ClassA(int value) : value_a_(value) {}

    void PrintClassBValue(const ClassB& class_b);
};

class ClassB {
private:
    int value_b_;

public:
    ClassB(int value) : value_b_(value) {}

    // ClassA의 private 멤버에 접근할 수 있도록 설정
    //friend class ClassA;

    const int GetValueB() const {
        return value_b_;
    }
};

void ClassA::PrintClassBValue(const ClassB& class_b) {
    cout << "Value from ClassB: " << class_b.GetValueB() << endl;
}

#pragma region override와 final 키워드 사용
class Base {
    virtual void Foo();
};

class Derived : public Base {
    void Foo() override;
};

class FinalDerived : public Derived {
    void Foo() final;
};
#pragma endregion

#pragma region 불필요한 복사 방지
void PrintValue(const std::string& value) {
    std::cout << value << std::endl;
}
#pragma endregion

//int main()
//{
//    // 옳바른
//    double d = 3.14;
//    int i = static_cast<int>(d);
//
//    // 잘못된
//    double d = 3.14;
//    int i = (int)d;
//
//    std::cout << "Hello World!\n";
//}
