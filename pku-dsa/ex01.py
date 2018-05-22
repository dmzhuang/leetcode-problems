#-*- coding: utf-8 -*-


class People(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name

    def getAge(self):
        return self.age


class Student(People):

    def __init__(self, name, age, id):
        super().__init__(name, age)
        self.id = id

    def getId(self):
        return self.id


class Xdict(dict):
    def getKeys(self, target):
        ret_val = []
        for key, value in self.items():
            if target == value:
                ret_val.append(key)
        return ret_val


class Vector(object):
    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)

    def __str__(self):
        #return '({x.1f},{y.1f},{z.1f})'.format(self.__dict__)
        return '(%.1f,%.1f,%.1f)' % (self.x, self.y, self.z)

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, n):
        return Vector(self.x * n, self.y * n, self.z * n)

    def __truediv__(self, n):
        return Vector(self.x / n, self.y / n, self.z / n)


try:
    #name = input()
    #age = int(input())
    #p = People(name, age)
    #print(p.getName(), p.getAge())

    #id = int(input())
    #student = Student(name, age, id)
    #print(student.getName(), student.getAge(), student.getId())

    #alist = list(input().split())
    #blist = list(input().split())
    #target = input()
    #d = Xdict(zip(alist, blist))
    #print(sorted(d.getKeys(target)))
 
    alist = list(input().split())
    blist = list(input().split())
    n = float(input())

    a = Vector(*alist)
    b = Vector(*blist)
    print(a+b, a-b, a*n, a/n)

except KeyboardInterrupt:
    pass
