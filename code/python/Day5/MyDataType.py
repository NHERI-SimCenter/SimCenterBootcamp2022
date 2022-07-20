from copy import copy

class MyDataType():

    def __init__(self, firstname='Jane', lastname='Doe', yob=2000):
        self.first_name = firstname
        self.last_name = lastname
        self.email = 'none@gmail.com'
        self.phone = '(000) 000-0000'
        self.YOB   = yob
        self._internal_var = 'stay away from this one'
        self.has_a_friend = False

    def __str__(self):
        s = \
"""
{} {}
email: {}
phone: {}
YOB:   {}""".format(self.first_name, self.last_name,
                    self.email, self.phone, self.YOB)
        if self.has_a_friend:
            s += "\nI have friend(s)"
        return s

    def __add__(self, other):

        if isinstance(other, MyDataType):
            self.has_a_friend = True
            other.has_a_friend = True

            ans = copy(self)
            ans.first_name += ' and ' + other.first_name

        elif isinstance(other, int):
            ans = copy(self)
            ans.YOB -= other

        else:
            ans = None

        return ans


if __name__ == '__main__':
    student1 = MyDataType(firstname='Jane', yob=2002)
    student2 = MyDataType(firstname='John', yob=2020)
    student2.email = 'john.doe@gmail.com'

    print(student1)
    print(student2)

    print("---")

    student1 + student2

    print(student1)
    print(student2)

    print("---")

    student3 = student1 + student2

    print(student3)

    print("---")

    student4 = student1 + 42

    print(student4)
