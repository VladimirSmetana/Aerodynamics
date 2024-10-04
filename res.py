import pandas as pd
import matplotlib.pyplot as plt


attack_angle = [2, 4, 6, 8, 10]
arrayH = [0, 10, 20, 40, 60]
# Создаем фигуру и подграфики
fig, axs = plt.subplots(2, 1, figsize=(10, 8))
plt.get_current_fig_manager().window.title('Аэродинамические коэффициенты')
# Чтение данных и построение первого графика (Cx)
for i in range(5):
    data = pd.read_csv(f'results/aero_file_{i}.csv')
    data.columns = data.columns.str.strip()
    axs[0].plot(data['Mah'], data['Cx'], label=f'{arrayH[i]} km')

axs[0].set_ylabel('Cx')
axs[0].set_title('Cx(Mah)')
axs[0].grid()
axs[0].legend()  # Добавление легенды для первого графика

# Чтение данных и построение второго графика (Cy)
for i in range(5):
    data = pd.read_csv(f'results/aero_file_{i}.csv')
    data.columns = data.columns.str.strip()
    axs[1].plot(data['Mah'], data['Cy'], label=f'{attack_angle[i]} deg')

axs[1].set_xlabel('Mah')
axs[1].set_ylabel('Cy')
axs[1].set_title('Cy(Mah)')
axs[1].grid()
axs[1].legend()  # Добавление легенды для второго графика

# Показ графиков
plt.tight_layout()  # Автоматическая настройка отступов
plt.show()
