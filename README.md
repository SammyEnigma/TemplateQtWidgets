# TemplateQtWidgets

QtWidgets project template for quick application creation with some implemented frequently encountered functionality. </br>
Features:
- The main window with some elements
- Internationalization - prepared ts-file and loading qm-file at startup
- Dynamic change of the language (locale) of the interface directly while the program is running
- Displaying information about the assembly of the application (Qt version, CPU architecture, etc.)
- A qrc resource file is connected
- For Windows: building exe and necessary dependencies in the path: {project directory} \ deploy {platform} in release mode
- For Windows: implemented executive file icon (Icon made by Freepik from www.flaticon.com)
- For Windows: implemented to obtain colorization colorization ColorizationColor from the QtWinExtras module
- For Windows: scripts and other files have been created to create the Inno Setup installer
- The C ++ class "Utils" is connected with its own static functions, which I often use in my projects

Шаблон проекта на QtWidgets для быстрого создания приложения с некоторым реализованным часто встречающимся функционалом.</br>
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
