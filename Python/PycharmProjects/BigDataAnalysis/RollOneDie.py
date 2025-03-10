import random
import plotly.express as px


class Die:
    def __init__(self, num_sides=6):
        self.num_sides = num_sides

    def roll(self):
        once = random.randint(1, self.num_sides)
        return once


die = Die()
results = []
for iNumber in range(1000):
    result = die.roll()
    results.append(result)

frequencies = []
poss_results = range(1, die.num_sides+1)
for value in poss_results:
    frequency = results.count(value)
    frequencies.append(frequency)

title = "The result of rolling D6 1000 times"
label = {'x': 'Results', 'y': 'Frequency of Results'}
fig = px.bar(x=poss_results, y=frequencies, title=title, labels=label)
fig.show()