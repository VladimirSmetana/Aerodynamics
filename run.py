import subprocess
import os

# Получаем текущую рабочую директорию
current_dir = os.getcwd()

# Построение путей относительно текущей рабочей директории
exe_path = os.path.join(current_dir, "out/build/GCC 4.9.2 i686-w64-mingw32/Debug/ARD.exe")
py_path = os.path.join(current_dir, "res.py")

# Запуск .exe файла
subprocess.run([exe_path])

# Открытие res.py файла
subprocess.run(["python", py_path])