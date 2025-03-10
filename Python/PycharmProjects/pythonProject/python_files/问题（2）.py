class Restaurant:
    def __int__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe(self):
        print(f'Welocme to {self.restaurant_name}, the type is {self.cuisine_type}.')

    def open(self):
        print('The restaurant is opening.')


restaurant = Restaurant('name', 'type')
restaurant.describe()
restaurant.open()

# 遇到错误 line 13 显示意外实参
# 如果插入  restaurant.restaurant_name = 'name'
#          restaurant.cuisine_type = 'type'  则可以正常运行
