class Adder:
    def __init__(self):  # initializer
        print('in __init__')

    def __del__(self):  # finalizer
        print('in __del__')

    def do_int(self, p1:int, p2:int, p3:int):
        print("do_int", p1, p2, p3)
        return p1 + p2 + p3

    def do_float(self, p1:float, p2:float, p3:float):
        print("do_float", p1, p2, p3)
        return p1 + p2 + p3

    def do_str(self, p1:str, p2:str, p3:str):
        print("do_str", p1, p2, p3)
        return p1 + p2 + p3


def main():
    print("in Python1.py", __name__)
    c1 = Adder()
    print(c1.do_int(2, 3, 4))
    print(c1.do_float(3.14, 9.8, 2.71828))
    print(c1.do_str("Joy", "Bear", "English"))


if __name__ == "__main__":
    main()
