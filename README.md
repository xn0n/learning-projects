# Learning Projects

**Учебные исходники: алгоритмы, desktop-интерфейсы и Android.**

Коллекция собственных учебных работ и ранних экспериментов. Сохранены содержательные и отличающиеся версии; пустые IDE-шаблоны и проекты, уже представленные отдельными репозиториями, не дублируются.

## Каталог

| Проект | Что делалось | Язык | Инструменты |
| --- | --- | --- | --- |
| [Автомат](cpp/shopping-receipt/README.md) | Расчёт покупки, скидки и чека | C++ | Visual Studio / MSBuild |
| [bitmask](cpp/bitmask-demo/README.md) | Проверка битовой маски на случайном массиве | C++ | Visual Studio / MSBuild |
| [Calculator](windows/calculator/README.md) | Калькулятор на C# и WinForms | C# / WinForms | Visual Studio / MSBuild |
| [Calculators](windows/calculator-versions/README.md) | Сохранённые варианты WinForms калькулятора | C# / WinForms | Visual Studio / MSBuild |
| [chatgpt1](cpp/game-experiments/README.md) | Консольные игровые эксперименты | C++ | Visual Studio / MSBuild |
| [chatgpt2](cpp/maze-flashlight/README.md) | Консольный лабиринт с фонариком | C++ | Visual Studio / MSBuild |
| [codewars](cpp/pointer-sum-draft/README.md) | Черновик упражнения с вводом и указателем | C++ | Visual Studio / MSBuild |
| [Count](cpp/oop-experiments/README.md) | Учебные эксперименты с классами и файлами | C++ | Visual Studio / MSBuild |
| [deixtra](windows/dijkstra-graph/README.md) | Граф и поиск кратчайшего пути на WinForms | C# / WinForms | Visual Studio / MSBuild |
| [Graf](windows/graph-variant/README.md) | Другая версия визуального графа и поиска пути | C# / WinForms | Visual Studio / MSBuild |
| [Lab4](cpp/shopping-receipt-lab4/README.md) | Лабораторный вариант расчёта покупки | C++ | Visual Studio / MSBuild |
| [learning](cpp/character-codes/README.md) | Преобразования между символом и числом | C++ | Visual Studio / MSBuild |
| [LeetCode](cpp/leetcode-basics/README.md) | Задачи на строки и римские числа | C++ | Visual Studio / MSBuild |
| [MazeSolver](windows/maze-pathfinder/README.md) | Поиск и визуализация пути в лабиринте | C# / WinForms | Visual Studio / MSBuild |
| [menushka](windows/cpp-learning-menu/README.md) | Учебное меню задач, фигур и кодирования | C++ | Visual Studio / MSBuild |
| [MyPractica](windows/recursion-graphs/README.md) | Рекурсивные вычисления, таблицы и графики | C++/CLI / WinForms | Visual Studio / MSBuild |
| [MyPractice](windows/bitmask-form/README.md) | Битовая маска через WinForms диалог | C++/CLI / WinForms | Visual Studio / MSBuild |
| [Project1](windows/bitmask-form-variant/README.md) | Вариант формы проверки битовой маски | C++/CLI / WinForms | Visual Studio / MSBuild |
| [Project2](windows/recursion-plot-fragment/README.md) | Фрагмент рекурсивных вычислений и графиков | C++/CLI / WinForms | Visual Studio / MSBuild |
| [stream](cpp/mystring-operators/README.md) | Учебный строковый класс с операторами | C++ | Visual Studio / MSBuild |
| [Translator](cpp/dictionary-translator/README.md) | Перевод текста по локальному словарю | C++ | Visual Studio / MSBuild |
| [uchebka](cpp/cpp-basics/README.md) | Набор базовых C++ упражнений | C++ | Visual Studio / MSBuild |
| [Kamen](android/rock-paper-scissors/README.md) | Камень, ножницы, бумага | Java / Android | Gradle / Android Studio |
| [Lab1](android/phrase-clicker/README.md) | События кнопки и обработка строк | Java / Android | Gradle / Android Studio |
| [MyApplication5](android/list-editor/README.md) | Список с добавлением и удалением | Java / Android | Gradle / Android Studio |
| [WindowsFormsApplication367](windows/maze-renderer/README.md) | Лабиринт с движением и областью видимости | C# / WinForms | Visual Studio / MSBuild |
| [DogAndCat](android/dog-and-cat/README.md) | Интерактивный экран с кошкой и собакой | Java / Android | Gradle / Android Studio |
| [Stone_1 · счёт](android/stone-with-score/README.md) | Вариант камень–ножницы–бумага со счётом | Java / Android | Gradle / Android Studio |
| [Stone_1 · другая версия](android/stone-alternate/README.md) | Другой вариант камень–ножницы–бумага | Java / Android | Gradle / Android Studio |

## Как изучать

Каждая папка содержит README с файлами реализации, возможностями и ограничениями. Небольшие консольные упражнения отделены от desktop и Android проектов. Варианты калькуляторов, графов и игр сохранены отдельно, поскольку их исходники различаются.

## Что потребуется

| Семейство | Предпосылки |
| --- | --- |
| C++ | Windows, Visual Studio, Desktop development with C++; toolset из проекта |
| C# / WinForms | Windows, Visual Studio и .NET Framework targeting pack проекта |
| C++/CLI / WinForms | Windows, Visual Studio с C++/CLI и .NET Framework 4.7.2 targeting pack |
| Android / Java | Android Studio, Android SDK, JDK и Gradle совместимых с build-файлами версий |

## Границы публикации

**Коллекция статически подготовлена; проекты не собирались и не запускались.** Исходники отражают разные этапы обучения, включая незавершённые упражнения. Проверки XML и отсутствия найденных секретов не доказывают правильность алгоритмов или готовность программы к использованию.

Из публичной копии исключены персональные данные, документы, входные наборы, фотографии, бинарные ресурсы, результаты сборки, IDE caches и локальные ключи. Ресурсные data/metadata в .resx удалены; Gradle wrapper JAR не включён. Поэтому части GUI и Android проектов потребуют восстановления собственных разрешённых ресурсов и инструментов перед сборкой.

В отдельных README отмечены известные ограничения исходников: некорректное использование памяти в pointer-sum-draft, отсутствующие зависимости recursion-plot-fragment и графические ресурсы maze-renderer.

Реальные секреты и абсолютные личные пути не нужны для изучения коллекции. Настройка SDK, paths и тестовых входных данных выполняется локально.
