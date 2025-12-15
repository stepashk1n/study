#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ProgramError {
public:
    virtual string what() const {
        return "Ошибка в программе";
    }
};

class lowpriviligies : public ProgramError {
public:
    string what() const override {
        return "Мало привелегий";
    }
};

class preobError : public ProgramError {
public:
    string what() const override {
        return "ошибка преоброзования";
    }
};

class unrealpreobError : public preobError {
public:
    string what() const override {
        return "невозможно привести к преоброзованию";
    }
};

class InterfaceError : public ProgramError {
public:
    string what() const override {
        return "Невозможно привести к интерфейсу";
    }
};

template<typename T>
class PrtArray {
private:
    T* data[10];
    int count = 0;
public:
    void add(T* ptr) {
        if (count < 10) {
            data[count++] = ptr;
        }
    }
    T*& operator[](int index) {
        return data[index];
    }
    int size() const {
        return count;
    }
};

class TestClass {
public:
    void print() const {
        cout << "TestClass" << endl;
    }
};

class Anotherclass {
public:
    void display() const {
        cout << "Anotherclass" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    PrtArray <ProgramError> errors;
    errors.add(new lowpriviligies());
    errors.add(new unrealpreobError());
    errors.add(new InterfaceError());

    cout << "Ошибка: " << endl;
    for (int i = 0; i < errors.size(); i++) {
        cout << errors[i]->what() << endl;
    }

    PrtArray<TestClass> testObjects;
    testObjects.add(new TestClass());
    testObjects.add(new TestClass());

    PrtArray<Anotherclass> anotherObjects;
    anotherObjects.add(new Anotherclass());

    cout << "\nТестовые объекты:" << std::endl;
    for (int i = 0; i < testObjects.size(); i++) {
        testObjects[i]->print();
    }

    cout << "\nДругие объекты:" << std::endl;
    for (int i = 0; i < anotherObjects.size(); i++) {
        anotherObjects[i]->display();
    }

    cout << "\nДоступ через оператор []:" << std::endl;
    testObjects[0]->print();


    for (int i = 0; i < errors.size(); i++) delete errors[i];
    for (int i = 0; i < testObjects.size(); i++) delete testObjects[i];
    for (int i = 0; i < anotherObjects.size(); i++) delete anotherObjects[i];

    return 0;
}
