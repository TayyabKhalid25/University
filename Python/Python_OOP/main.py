import datetime  # For LibraryItem


# Simple Classes
class Car:
    def __init__(self, n, e):  # Constructor
        self.__VehicleID = n  # Two underscore characters before an attribute name signify it is private.
        self.__Registration = ''
        self.__Date0fRegistration = None
        self.__EngineSize = e
        self.__PurchasePrice = 0.00

    def setpurchaseprice(self, p):  # Setter
        self.__PurchasePrice = p

    def getpurchaseprice(self):  # Getter
        return self.__PurchasePrice

    @property  # Usage of Properties
    def registration(self):
        return self.__Registration

    @registration.setter  # Needed to allow changing value of property.
    def registration(self, r):
        self.__Registration = r


#  Base Class and Derived Classes:
class LibraryItem:  # Base Class Definition
    def __init__(self, t=None, a=None, i=None):  # Put None or any value so that function/class may be called without
        # that particular parameter as well, and therefore make different outcomes.
        self.__Title = t
        self.__Author__Artist = a
        self.__ItemID = i
        self.__OnLoan = False
        self.__DueDate = datetime.date.today()

    def gettitle(self):
        return self.__Title

    def borrowing(self):
        self.__OnLoan = True
        self.__DueDate = self.__DueDate + datetime.timedelta(weeks=3)

    def printdetails(self):  # Fumctions to be Overridden dont have to be declared so like VB.
        print(self.__Title, self.__Author__Artist, sep=' , ')
        print(self.__ItemID, self.__OnLoan, self.__DueDate, sep=' , ')


class Book(LibraryItem):  # Subclass Definition
    def __init__(self, t, a, i):
        LibraryItem.__init__(self, t, a, i)
        self.__IsRequested = False
        self.__RequestedBy = 0

    def getisrequested(self):
        return self.__IsRequested

    def printdetails(self):  # Example of Overriding a function in parent class.
        print('Book Details:')
        LibraryItem.printdetails(self)  # This line calls the base class method with the same name.
        print(self.__IsRequested)


class CD(LibraryItem):
    def __init__(self, t, a, i):
        LibraryItem.__init__(self, t, a, i)
        self.__Genre = ''

    def getgenre(self):
        return self.__Genre

    def setgenre(self, g):
        self.__Genre = g


# Containment(aggregation): a relationship in which one class has a component that is of another class type.
