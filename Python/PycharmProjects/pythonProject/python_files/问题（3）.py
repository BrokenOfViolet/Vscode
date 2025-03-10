class Restaurant:
    def __int__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        self.number_served = None
        self.add_person = None

    def describe(self):
        print(f'Welocme to {self.restaurant_name}, the type is {self.cuisine_type}.')

    def open(self):
        print(f'The restaurant {self.restaurant_name} is opening.')

    def services(self):
        print(f'The restaurant was severd {self.number_served} people in totle.')
        print(f'the add number of person is: {self.add_person}')

    def increment_number_served(self):
        self.number_served += self.add_person
        print(f'Now the person we severd are {self.number_served} people.')


class IceCreamRest(Restaurant):
    def __init__(self, restaurant_name, cuisine_type):
        super().__init__(self, restaurant_name, cuisine_type)


rest = IceCreamRest("Ice rest", "Ice Cream")
rest.describe()

