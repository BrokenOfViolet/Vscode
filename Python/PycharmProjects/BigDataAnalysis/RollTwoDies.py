import random
import plotly.express as px


class Die:
    def __init__(self, num_sides=6):
        self.num_sides = num_sides

    def roll(self):
        once = random.randint(1, self.num_sides)
        return once


die1 = Die()
die2 = Die()
results = []
for iNumber in range(1000):
    result = die1.roll() + die2.roll()
    results.append(result)

frequencies = []
max_result = die1.num_sides + die2.num_sides
poss_results = range(2, max_result+1)
for value in poss_results:
    frequency = results.count(value)
    frequencies.append(frequency)

title = "The result of rolling Two D6 1000 times"
label = {'x': 'Results', 'y': 'Frequency of Results'}
fig = px.bar(x=poss_results, y=frequencies, title=title, labels=label)
fig.update_layout(xaxis_dtick=1)
# path = "DataSet"
# fig.write_html(path+'/RollTwoDiesResult.html')
# 用于保存html文件到path目录下
fig.show()