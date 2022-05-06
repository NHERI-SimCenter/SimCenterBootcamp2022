# **************************************************************************
# 
# class: Human ... representing a human by name, gender, date of birth
#
# author:    Peter Mackenzie-Helnwein
# created:   pmh - 10/28/2020
# modified: 
#
# **************************************************************************

class Human():
    """
    Representation of a Human

    variables:
        self.firstname
        self.lastname
        self.gender
        self.date_of_birth

    methods:
        __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01')
        __str__(self)
        __repr__(self)
        __eq__(self,other)   ... implements == between Human objects
        __ne__(self,other)   ... implements != between Human objects
        first_name(self)
        last_name(self)
        full_name(self)
    """

    def __init__(self,first='unknown',last='unknown',gender='unknown',dob='2000-01-01'):
        self.firstname = first
        self.lastname  = last
        self.gender    = gender
        self.date_of_birth = dob

    def __str__(self):
        s =  "First name:    {}\n".format(self.firstname)
        s += "Last name:     {}\n".format(self.lastname)
        s += "Gender:        {}\n".format(self.gender)
        s += "date of birth: {}\n".format(self.date_of_birth)
        return s

    def __repr__(self):
        template="{}(first='{}',last='{}',gender='{}',dob='{}')"
        s = template.format(self.__class__.__name__,   # this holds the name of the class and will work if inherited
                            self.firstname,
                            self.lastname,
                            self.gender,
                            self.date_of_birth)
        return s
    
    def __eq__(self,other):
        ans = True
        if self.firstname != other.firstname:
            ans = False
        if self.lastname != other.lastname:
            ans = False
        if self.gender != other.gender:
            ans = False
        if self.date_of_birth != other.date_of_birth:
            ans = False
        return ans
    
    def __ne__(self,other):
        ans = True
        if self.firstname == other.firstname:
            ans = False
        if self.lastname == other.lastname:
            ans = False
        if self.gender == other.gender:
            ans = False
        if self.date_of_birth == other.date_of_birth:
            ans = False
        return ans

    def first_name(self):
        return self.firstname

    def last_name(self):
        return self.lastname

    def full_name(self):
        return "{} {}".format(self.firstname, self.lastname)

