class FamilyTree():
    """
    managing an entire family

    variables:
        self.family_tree_name
        self.members = []

    methods (required):
        __init__(self,name='unknown')
        __str__(self)
        __repr__(self)
        family_name(self)
        set_family_name(self,name)
        all_men(self)
        all_women(self)
        individuals(self,key='all')
        individual(self,name)
        add_individual(self,guy)
        tree_print(self)

    methods (added to simplify implementation of required methods):
        name_list(self,key='all')   ... like individuals() but returns names instead pf pointers
        find_eldest(self)           ... return the oldest male and the oldest female
        print_individual(self,person,level=0)       ... print information for person.
                                                        level for hirachy/indentation
        print_children(self,person,partner,level=0,exclusion=[])
                                                    ... print children shared by person and partner.
                                                        level for hirachy/indentation
    """

    # ==== overloading default methods ========

    def __init__(self, name='unknown'):
        self.family_tree_name = name
        self.members = []

    def __str__(self):
        s = "Family Tree Name: {}\n".format(self.family_tree_name)
        s += "-----------------------------------------\n"
        cnt = 0
        for person in self.members:
            cnt += 1
            s += "  {}: {}\n".format(cnt, person.full_name())
        return s

    def __repr__(self):
        return "{}(name='{}')".format(self.__class__.__name__, self.family_tree_name)

    # ==== interface methods (required by problem statement) ========

    def family_name(self):
        return self.family_tree_name

    def set_family_name(self, name):
        self.family_tree_name = name

    def all_men(self):
        return self.name_list('male')

    def all_women(self):
        return self.name_list('female')

    def individuals(self, key='all'):
        if key not in ['all', 'male', 'female']:
            raise TypeError

        if key == 'all':
            ans = self.members[:]
        else:
            ans = []
            for person in self.members:
                if person.gender == key:
                    ans.append(person)
        return ans

    def individual(self, name):
        ans = []
        names = name.strip().split(' ')
        for person in self.members:
            # see if this one is a candidate ...
            if (len(names) == 1) and ((person.first_name() in names) or (person.last_name() in names)):
                ans.append(person)
            elif (len(names) > 1) and (person.first_name() in names) and (person.last_name() in names):
                ans.append(person)
        return tuple(ans)

    def add_individual(self, guy):
        if guy not in self.members:
            self.members.append(guy)

    def tree_print(self):
        start = self.find_eldest()

        tree = "\nFamily Tree Name: {}\n".format(self.family_tree_name)
        tree += "-----------------------------------------"
        print(tree)
        for lady in start['female']:
            self.print_individual(lady)
        for gent in start['male']:
            self.print_individual(gent)

    # ==== internal use methods ========

    def name_list(self, key='all'):
        lst = self.individuals(key)
        ans = []
        for person in lst:
            ans.append(person.full_name())
        return ans

    def find_eldest(self):
        eldest = {'male': [], 'female': []}
        for person in self.members:
            if not person.parents():
                eldest[person.gender].append(person)
        return eldest

    def print_individual(self, person, level=0):
        exclude = []
        if person.partner():
            for partner in person.partner():
                name = level * '>' + level * '  ' + person.full_name() + '\t<=>\t' + partner.full_name()
                print(name)
                self.print_children(person, partner, level)
                exclude += partner.children()
        name = level * '>' + level * '  ' + person.full_name()
        print(name)
        self.print_children(person, person, level, exclusion=exclude)

    def print_children(self, person, partner, level=0, exclusion=[]):
        for child in person.children():
            if (child in partner.children()) and (child not in exclusion):
                self.print_individual(child, level + 1)
