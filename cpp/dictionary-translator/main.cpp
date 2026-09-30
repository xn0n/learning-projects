#include <iostream>
#include <map>
#include <string>

using namespace std;

// Функция перевода слова
string translateWord(string word, map<string, string> dictionary) {
    if (dictionary.count(word) > 0) {
        return dictionary[word];
    }
    else {
        return "Слово не найдено";
    }
}

// Функция перевода текста
string translateText(string text, map<string, string> dictionary) {
    string translatedText = "";

    // Разделение текста на слова с помощью цикла for и итератора
    for (int i = 0; i < text.size(); ++i) {
        string word = "";
        while (text[i] != ' ' && i < text.size()) {
            word += text[i];
            i++;
        }

        translatedText += translateWord(word, dictionary) + " ";
    }

    // Удаление лишнего пробела
    return translatedText.substr(0, translatedText.size() - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    // Словарь (в данном случае русский-английский)
    map<string, string> dictionary = {
      {"привет", "hello"},
      {"мир", "world"},
      {"как", "how"},
      {"ты", "you"},
      {"дела", "are"},
      {"сегодня", "today"},
      {"хорошо", "good"},
      {"я", "I"},
      {"зовут", "name"},
      {"меня", "me"},
      {"Бард", "Bard"},
      {"искусственный", "artificial"},
      {"интеллект", "intelligence"},
      {"могу", "can"},
      {"переводить", "translate"},
      {"тексты", "texts"},
      {"с", "from"},
      {"на", "to"},
      {"разные", "different"},
      {"языки", "languages"},
      // ... (добавьте больше слов в словарь)
    };

    // Запрос текста у пользователя
    string inputText;
    cout << "Введите текст на русском: ";
    getline(cin, inputText);

    // Перевод текста
    string translatedText = translateText(inputText, dictionary);

    // Вывод перевода
    cout << "Перевод на английском: " << translatedText << endl;

    return 0;
}
