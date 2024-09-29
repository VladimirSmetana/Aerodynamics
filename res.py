import pandas as pd
import matplotlib.pyplot as plt


# plt.axis([0,5,0,0.45])
plt.subplot(2, 1, 1)
for i in range(0,5):

    data = pd.read_csv('results/aero_file_'+str(i)+'.csv')
    data.columns = data.columns.str.strip()
    plt.plot(data['Mah'], data['Cx'])

# plt.xlabel('Mah')
plt.ylabel('Cx')
# plt.title('Cx(Mah)')
plt.grid()

# plt.axis([0,5,0.001,0.011])
plt.subplot(2, 1, 2)
for i in range(0,5):

    data = pd.read_csv('results/aero_file_'+str(i)+'.csv')
    data.columns = data.columns.str.strip()
    plt.plot(data['Mah'], data['Cy'])

plt.xlabel('Mah')
plt.ylabel('Cy')
# plt.title('Cy(Mah)')


plt.grid()
plt.show()
