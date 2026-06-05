# 📚 LibraryManager

*Простой настольный менеджер библиотеки на Qt6 — учёт книг и выдачи экземпляров.*

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-6-41CD52?logo=qt&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.19%2B-064F8C?logo=cmake&logoColor=white)

## ✨ Возможности

- **Список книг** — отображение каталога в виде `QListView` в формате `Название | Автор | Год | Количество`.
- **Добавление книги** — отдельное окно с полями: название, автор, год, количество.
- **Редактирование** — открывается двойным кликом по записи в списке.
- **Выдача экземпляра** — кнопка «Get» уменьшает количество доступных копий (не уходит ниже нуля).
- **Возврат экземпляра** — кнопка «Return» увеличивает количество копий.
- Данные хранятся в памяти приложения через собственную модель на базе `QAbstractListModel`.

## 🛠 Стек

- **Язык:** C++
- **GUI:** Qt 6 (модули Core, Widgets)
- **Сборка:** CMake (`qt_add_executable`, `qt_standard_project_setup`)
- **Архитектура:** Model/View — кастомная модель `BookModelClass` поверх `QAbstractListModel`

## 🚀 Сборка и запуск

Требуется Qt 6.5+ и компилятор MinGW или MSVC.

```powershell
cmake -B build -S . ; cmake --build build --config Debug
```

Собранный исполняемый файл `LibraryManager` появится в каталоге `build/`.

## 📂 Структура

```
LibraryManager/
├── CMakeLists.txt        # конфигурация сборки
├── main.cpp              # точка входа, создание модели и окна
├── Book.h                # структура данных книги (id, title, author, year, count)
├── bookmodelclass.h/.cpp # модель данных (QAbstractListModel)
├── mainwindow.h/.cpp/.ui # главное окно со списком книг
├── addwindow.h/.cpp/.ui  # окно добавления книги
└── editwindow.h/.cpp/.ui # окно редактирования / выдачи / возврата
```

---

<sub>Учебный pet-проект на Qt6. Сделано для практики Model/View в Qt.</sub>
