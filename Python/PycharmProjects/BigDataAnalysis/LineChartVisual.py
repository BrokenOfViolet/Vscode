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
    rw = RandomWalk(num_points=500)
    rw.fill_walk()
    plt.style.use('seaborn-v0_8')
    fig, ax = plt.subplots(figsize=(10, 6))
    point_numbers = range(rw.num_points)
    ax.set_title("Simulated pollen movement", fontsize=24)
    ax.plot(rw.x_values, rw.y_values, linewidth=1.5)

    ax.scatter(0, 0, c='green', edgecolor='none', s=20)
    ax.scatter(rw.x_values[-1], rw.y_values[-1], c='red', edgecolor='none', s=20)

    ax.set_aspect('equal')
    plt.show()

    keep_running = input("Make another walk? (y/n)")
    if keep_running == 'n':
        break

print("The programme over.")