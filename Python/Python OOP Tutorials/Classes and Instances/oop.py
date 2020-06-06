import datetime
import os

class Employee:

    raise_amount = 1.04
    num_of_emps = 0
    
    # This is similar to a constructor
    def __init__(self, first_name, last_name, pay):
        self.first_name = first_name
        self.last_name = last_name
        self.pay = pay

        Employee.num_of_emps += 1

    # This is a method, but it can be accessed like a property - cool right? BTW: This is a getter
    @property
    def email(self):
        return '{}, {}@company.com'.format(self.first_name, self.last_name)
    
    # This is an alternative constructor AKA constructor overriding
    @classmethod
    def from_string(cls, emp_str):
        first_name, last_name, pay = emp_str.split('-')
        return cls(first_name, last_name, pay)


    @property
    def full_name(self):
        return '{} {}'.format(self.first_name, self.last_name)

    @full_name.setter
    def full_name(self, name):
        first_name, last_name = name.split(' ')
        self.first_name = first_name
        self.last_name = last_name

    @full_name.deleter
    def full_name(self):
        self.first_name = None
        self.last_name = None

    # Regular method
    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amount)

    # In this method we are working with the class instead of the instance
    @classmethod
    def set_raise_amount(cls, amount):
        cls.raise_amount = amount

    @staticmethod
    def is_workday(day):
        if day.weekday() == 5 or day.weekday() == 6:
            return False
        return True

    def __repr__(self):
        return "Employee('{}', '{}', {})".format(self.first_name, self.last_name, self.pay)

    def __str__(self):
        return '{} - {}'.format(self.full_name, self.email)

    def __add__(self, other):
        return self.pay + other.pay

    def __len__(self):
        return len(self.full_name)

class Developer(Employee): # Inherets from Employee class
    raise_amount = 1.10

    # This is similar to a constructor
    def __init__(self, first_name, last_name, pay, prog_lang):
        super().__init__(first_name, last_name, pay) # Calling the constructor of the parent class
        self.prog_lang = prog_lang

class Manager(Employee):

    def __init__(self, first_name, last_name, pay, employees=None):
        super().__init__(first_name, last_name, pay)
        if employees is None:
            self.employees = []
        else:
            self.employees = employees

    def add_employee(self, employee):
        if employee not in self.employees:
            self.employees.append(employee)

    def remove_employee(self, employee):
        if employee in self.employees:
            self.employees.remove(employee)

    def print_employees(self):
        for employee in self.employees:
            print("-->", employee.full_name)

def main():
    dev_1 = Developer('Cumar', 'Cabdiraxmaan', 125000, 'C++')
    dev_2 = Developer('Ahmed', 'Ali', 100000, 'Python')
    dev_3 = Developer('Mohamed', 'Abdi', 130000, 'Node.js')

    mngr_1 = Manager('Mohamed-Hani', 'Abdillahi', 225000, [dev_1, dev_2])

    emp_1 = Employee('Mohamed-Hani', 'Abdillahi', 225000)

    #print(help(Developer)) displays helpful information
    #print(isinstance(mngr_1, Manager))
    #print(issubclass(Developer, Employee))

    print(os.environ.get('HOME'))

    '''
    print(mngr_1.email)
    mngr_1.print_employees()
    print('----------------------------------')
    mngr_1.add_employee(dev_3)
    mngr_1.print_employees()
    print('----------------------------------')
    mngr_1.remove_employee(dev_1)
    mngr_1.print_employees()
    -----------------------------------------
    print(repr(emp_1))
    print(str(emp_1))
    -----------------------------------------
    print(dev_2 + dev_3)
    print(len(mngr_1))
    -----------------------------------------
    '''

if __name__ == "__main__":
    main()