# TemplateQtWidgets
Шаблон проекта на QtWidgets для быстрого создания приложения с некоторым реализованным часто встречающимся функционалом</br>
Особенности:
- Главное окно с некоторыми элемениами
- Интернационализация - подготовлены ts-файл и загрузка qm-файла при запуске
- Динамическое изменение языка (локали) интефейса прямо во время работы программы
- Вывод информации о сборке приложения (Версия Qt, архитектура CPU и др.)
- Подключён qrc-файл ресурсов
- Для Windows: сборка exe и необходимых зависимостей в путь: {директория проекта}\deploy{платформа} в режиме выпуска
- Для Windows: реализована иконка исполнительного файла (Icon made by Freepik from www.flaticon.com)
- Для Windows: реализовано получение цвета раскрашевания ColorizationColor из модуля QtWinExtras
- Для Windows: созданы скрипты и другие файлы для создания инсталлятора Inno Setup
- Подключён C++ класс "Utils" с собственными статическими функциями, которые часто использую в своих проектах
