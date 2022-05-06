from Individual import *
from FamilyTree import *

class Assignment5():

    def setup1(self):
        human1 = Human()
        human2 = Human(first='John',last='Doe',gender='male',dob='1950-07-04')

        print(repr(human1))
        print(human1)
        print(repr(human2))
        print(human2)


    def setup2(self):
        # creating Individuals

        self.dad  = Individual(first='Bob',last='Parr',gender='male',dob='1985-01-02')
        self.mom  = Individual(first='Helen',last='Parr',gender='female',dob='1980-03-04')
        self.girl = Individual(first='Violet',last='Parr',gender='female',dob='2002-05-06')
        self.boy  = Individual(first='Dash',last='Parr',gender='male',dob='2004-07-08')

        # connecting individuals

        self.mom.add_partner(self.dad)
            # dad.add_partner(mom) ... done automatically

        self.mom.add_child(self.girl)
            # girl.add_parent(mom) ... done automatically
        self.mom.add_child(self.boy)
            # boy.add_parent(mom) ... done automatically
        self.dad.add_child(self.girl)
            # girl.add_parent(dad) ... done automatically
        self.dad.add_child(self.boy)
            # boy.add_parent(dad) ... done automatically

        print(self.mom)
        print(self.dad)
        print(self.girl)
        print(self.boy)

    def run_family1(self):
        self.setup2()

        # 3.1 Test family #1

        family1 = FamilyTree()
        family1.set_family_name('The Incredibles')

        family1.add_individual(self.girl)
        family1.add_individual(self.boy)
        family1.add_individual(self.mom)
        family1.add_individual(self.dad)
        family1.add_individual(Individual(first='Jack-Jack', last='Parr', gender='male', dob='2005-09-10'))

        self.boy2 = family1.individual('Jack-Jack')
        if self.boy2:  # this is false is boy2==tuple(), true if boy2 contains Individual objects
            self.boy2[0].add_parent(self.mom)
            self.boy2[0].add_parent(self.dad)

        print(family1)

        family1.tree_print()

    def run_family2(self):
        # 3.2 Test family #2

        family2 = FamilyTree()
        family2.set_family_name('The Ducks')

        donald = Individual(first='Donald', last='Duck', gender='male', dob='1937-01-01')
        daisy = Individual(first='Daisy', last='Duck', gender='female', dob='1938-01-01')
        gladstone = Individual(first='Gladstone', last='Gander', gender='male', dob='1937-01-01')
        scrooge = Individual(first='Scrooge', last='McDuck', gender='male', dob='1900-01-01')
        grandma = Individual(first='Grandma', last='Duck', gender='female', dob='1900-01-21')
        huey = Individual(first='Huey', last='Duck', gender='male', dob='1948-11-01')
        dewey = Individual(first='Dewey', last='Duck', gender='male', dob='1949-11-01')
        louie = Individual(first='Louie', last='Duck', gender='male', dob='1950-11-01')
        april = Individual(first='April', last='Duck', gender='female', dob='1948-01-01')
        may = Individual(first='May', last='Duck', gender='female', dob='1949-01-01')
        june = Individual(first='June', last='Duck', gender='female', dob='1950-01-01')
        quackmore = Individual(first='Quackmore', last='Duck', gender='male', dob='1935-01-01')
        greatgrandma = Individual(first='GreatGrandma', last='Duck', gender='female', dob='1878-01-21')
        newey = Individual(first='Newey', last='Duck', gender='male', dob='1956-11-01')

        grandma.add_child(donald)
        grandma.add_child(gladstone)
        grandma.add_child(quackmore)
        quackmore.add_child(huey)
        quackmore.add_child(dewey)
        quackmore.add_child(louie)
        donald.add_partner(daisy)
        grandma.add_parent(greatgrandma)
        scrooge.add_parent(greatgrandma)
        april.add_parent(daisy)
        may.add_parent(daisy)
        daisy.add_child(june)
        newey.add_parent(daisy)
        newey.add_parent(donald)

        for person in [donald, daisy, gladstone, scrooge, grandma, huey,
                       dewey, louie, april, may, june, quackmore, greatgrandma, newey]:
            family2.add_individual(person)

        print(family2)

        family2.tree_print()

# executing the assignment
HW=Assignment5()

HW.run_family1()
HW.run_family2()
