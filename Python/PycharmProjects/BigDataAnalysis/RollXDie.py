import random
import plotly.express as px


class Die:
    def __init__(self, num_sides=6):
        self.num_sides = num_sides

    def roll(self):
        once = random.randint(1, self.num_sides)
        return once


die1 = die2 = Die(num_sides=6)
results = []
roll_times = 5000
for iNumber in range(roll_times):
    result = die1.roll() * die2.roll()
    results.append(result)

# results = [die1.roll() * die2.roll() for i in range(roll_times)]
# 列表推导式

frequencies = []
max_point = die1.num_sides * die2.num_sides
poss_results = range(1, max_point+1)
for value in poss_results:
    frequency = results.count(value)
    frequencies.append(frequency)

title = f"The result of rolling three D6 {roll_times} times"
label = {'x': 'Results', 'y': 'Frequency of Results'}
fig = px.bar(x=poss_results, y=frequencies, title=title, labels=label)
fig.update_layout(xaxis_dtick=1)
fig.write_html("DataSet/RollTwoD6Multiple.html")
fig.show()