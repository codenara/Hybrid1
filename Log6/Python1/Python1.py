def do_int(p1:int, p2:int, p3:int):
    print("do_int", p1, p2, p3)
    return p1 + p2 + p3


def do_float(p1:float, p2:float, p3:float):
    print("do_float", p1, p2, p3)
    return p1 + p2 + p3


def do_str(p1:str, p2:str, p3:str):
    print("do_str", p1, p2, p3)
    return p1 + p2 + p3


def main():
    print(do_int(2, 3, 4))
    print(do_float(3.14, 9.8, 2.71828))
    print(do_str("Joy", "Bear", "English"))


if __name__ == "__main__":
    main()
