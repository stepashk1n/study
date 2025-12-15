#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    string name;
    string price;
};

class Shop {
public:
    string shopname;
    vector<Product> products;

    Shop(string n) {
        shopname = n;
        cout << "Магазин - " << shopname << endl;
        cout << endl;
    }

    void addproduct() {
        Product p;

        cout << "Введите название товара: ";
        getline(cin, p.name);

        cout << "Введите цену товара: ";
        getline(cin, p.price);

        products.push_back(p);

        cout << "Продукт " << p.name << " добавлен" << endl;
        cout << endl;
    }

    void showproduct() {
        cout << "Все продукты в магазине " << shopname << endl;
        for (int i = 0; i < products.size(); i++) {
            cout << i + 1 << ". " << products[i].name << ' ' << products[i].price << " - РУБ." << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    string storeName;
    cout << "Введите название магазина: ";
    getline(cin, storeName);

    Shop myStore(storeName);
    string choice;

    do {
        cout << "Хотите ли вы добавить продукт? (y, n) " << endl;
        getline(cin, choice);

        if (choice == "y" || choice == "Y") {
            myStore.addproduct();
        }
    } while (choice == "y" || choice == "Y");

    myStore.showproduct();
    return 0;
}
