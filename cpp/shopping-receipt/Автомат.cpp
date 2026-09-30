#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
};

class CashRegister {
private:
    vector<Product> cart;
    double totalAmount;

public:
    CashRegister() : totalAmount(0.0) {}

    void addItem(const Product& product, int quantity = 1) {
        for (int i = 0; i < quantity; ++i) {
            cart.push_back(product);
            totalAmount += product.price;
        }
        cout << quantity << " " << product.name << "(ов) добавлено в корзину." << endl;
    }

    void applyDiscount(double discountPercentage) {
        double discountAmount = totalAmount * (discountPercentage / 100.0);
        totalAmount -= discountAmount;
        cout << "Скидка " << fixed << setprecision(2) << discountAmount << " применена." << endl;
    }

    void generateReceipt(bool withReceipt) {
        if (withReceipt) {
            cout << "\n----- Чек -----\n";
            for (const Product& product : cart) {
                cout << product.name << ": " << fixed << setprecision(2) << product.price << " руб.\n";
            }
            cout << "Итоговая сумма: " << fixed << setprecision(2) << totalAmount << " руб.\n";
            cout << "---------------\n";
        }
        else {
            cout << "Итоговая сумма без чека: " << fixed << setprecision(2) << totalAmount << " руб.\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    CashRegister cashier;
    Product item1 = { "Хлеб", 1.50 };
    Product item2 = { "Молоко", 2.00 };
    Product item3 = { "Яйца", 19 };

    int choice;

    do {
        cout << "\n----- Меню -----\n";
        cout << "1. Добавить товар\n";
        cout << "2. Применить скидку\n";
        cout << "3. Генерировать чек\n";
        cout << "4. Выйти\n";
        cout << "Выберите опцию (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            int quantity;
            cout << "Введите количество товара: ";
            cin >> quantity;
            cout << "Выберите товар:\n";
            cout << "1. Хлеб\n";
            cout << "2. Молоко\n";
            cout << "3. Яйца\n";
            int productChoice;
            cin >> productChoice;

            switch (productChoice) {
            case 1:
                cashier.addItem(item1, quantity);
                break;
            case 2:
                cashier.addItem(item2, quantity);
                break;
            case 3:
                cashier.addItem(item3, quantity);
                break;
            default:
                cout << "Неверный выбор товара.\n";
                break;
            }
            break;

        case 2:
            double discount;
            cout << "Введите процент скидки: ";
            cin >> discount;
            cashier.applyDiscount(discount);
            break;

        case 3:
            cout << "Выберите вариант генерации чека:\n";
            cout << "1. С чеком\n";
            cout << "2. Без чека\n";
            int receiptChoice;
            cin >> receiptChoice;

            switch (receiptChoice) {
            case 1:
                cashier.generateReceipt(true);
                break;
            case 2:
                cashier.generateReceipt(false);
                break;
            default:
                cout << "Неверный выбор. Используется чек по умолчанию.\n";
                cashier.generateReceipt(true);
                break;
            }
            break;

        case 4:
            cout << "До свидания!\n";
            break;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }

        // Очистка буфера ввода
        while (getchar() != '\n');
        
    } while (choice != 4);
    system("cls");

    return 0;
}
