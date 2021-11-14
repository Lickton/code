class Dog:
    def __init__(self, breed):
        self.breed = breed
        self.lifeP = 100
    
    def bite(self, Cat):
        Cat.lifeP -= 20 if self.breed == '京巴' else  80
    
    def showLP(self):
        print('%s has %d life points left.'%(self.breed, self.lifeP))

class Cat:
    def __init__(self, age):
        self.age = age
        self.lifeP = 100

    def attack(self, Dog):
        Dog.lifeP -= 10 if self.age <= 2 else 40

    def showLP(self):
        print('Cat has %d life points left.'%self.lifeP)

dog = Dog('藏獒')
cat = Cat(4)

dog.bite(cat)
cat.attack(dog)

dog.showLP()
cat.showLP()