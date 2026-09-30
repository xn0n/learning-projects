#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Структура для представления товара
struct Product {
    string name;
    double price;
};

// Класс кассы
class CashRegister {
private:
    vector<Product> cart;
    double totalAmount;

public:
    CashRegister() : totalAmount(0.0) {}

    // Метод для добавления товара в корзину
    void addItem(const Product& product, int quantity = 1) {
        for (int i = 0; i < quantity; ++i) {
            cart.push_back(product);
            totalAmount += product.price;
        }
        cout << quantity << " " << product.name << "(ов) добавлено в корзину." << endl;
    }

    // Метод для применения скидки
    void applyDiscount(double discountPercentage) {
        double discountAmount = totalAmount * (discountPercentage / 100.0);
        totalAmount -= discountAmount;
        cout << "Скидка " << fixed << setprecision(2) << discountAmount << " применена. Итоговая сумма: " << totalAmount << endl;
    }

    // Метод для расчета итоговой суммы и выдачи чека
    void generateReceipt() {
        cout << "\n----- Чек -----\n";
        for (const Product& product : cart) {
            cout << product.name << ": " << fixed << setprecision(2) << product.price << " руб.\n";
        }
        cout << "Итоговая сумма: " << fixed << setprecision(2) << totalAmount << " руб.\n";
        cout << "---------------\n";
    }
};

int main() {
    // Создаем объект кассы
    CashRegister cashier;

    // Создаем несколько товаров
    Product item1 = { "Хлеб", 1.50 };
    Product item2 = { "Молоко", 2.00 };
    Product item3 = { "Яйца", 1.20 };

    // Добавляем товары в корзину
    cashier.addItem(item1, 2);
    cashier.addItem(item2);
    cashier.addItem(item3, 3);

    // Применяем скидку
    cashier.applyDiscount(10.0);

    // Генерируем чек
    cashier.generateReceipt();

    return 0;
}
