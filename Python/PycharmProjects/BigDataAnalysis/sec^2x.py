import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0.01, 2 * np.pi, 1000)  # 从一个小值开始以避免除以零
sec_squared = 1 / np.cos(x)**2  # 计算 sec^2(x)

plt.figure(figsize=(8, 6))
plt.plot(x, sec_squared, label=r'$\text{sec}^2(x)$')
plt.title('Graph of sec^2(x)')
plt.xlabel('x')
plt.ylabel('sec^2(x)')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(color='gray', linestyle='--', linewidth=0.5)
plt.ylim(0, 10)  # 设置 y 轴范围
plt.legend()
plt.show()
