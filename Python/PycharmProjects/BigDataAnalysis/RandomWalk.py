import matplotlib.pyplot as plt
import random


class RandomWalk:
    def __init__(self, num_points=5000):
        self.num_points = num_points
        self.x_values = [0]
        self.y_values = [0]

    def fill_walk(self):
        while len(self.x_values) < self.num_points:
            x_step = self.get_step()
            y_step = self.get_step()

            if x_step == 0 and y_step == 0:
                continue

            x = self.x_values[-1] + x_step
            y = self.y_values[-1] + y_step

            self.x_values.append(x)
            self.y_values.append(y)

    def get_step(self):
        direction = random.choice([1, -1])
        distance = random.randint(1, 5)
        step = direction * distance
        return step


while True:
    rw = RandomWalk()
    rw.fill_walk()
    plt.style.use('classic')
    fig, ax = plt.subplots(figsize=(10, 6))
    point_numbers = range(rw.num_points)
    ax.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.Blues, edgecolors='none', s=15)
    # edgecolor = 'none'用于消除每个点的轮廓，且颜色映射的规律为由浅到深
    
    ax.scatter(0, 0, c='green', edgecolor='none', s=50)
    ax.scatter(rw.x_values[-1], rw.y_values[-1], c='red', edgecolor='none', s=50)

    ax.set_aspect('equal')
    # ax.get_xaxis().set_visible(False)
    # ax.get_yaxis().set_visible(False)
    # hide the aixs
    plt.show()

    keep_running = input("Make another walk? (y/n)")
    if keep_running == 'n':
        break

print("The programme over.")