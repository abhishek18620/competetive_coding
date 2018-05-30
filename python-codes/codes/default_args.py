class EvenStream(object):
    def __init__(self):
        self.current = 0

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return

class OddStream(object):
    def __init__(self):
        self.current = 1

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return

def print_from_stream(n, stream=EvenStream()):
    start=0
    for _ in range(n):
        num=stream.get_next()
        # even
        if num%2==0:
            print(start)
            start=start+2
        else:
            print(num)


f=open("INP.txt","r")
queries = int(f.readline())
for _ in range(queries):
    stream_name, n = f.readline().split()
    n = int(n)
    #print("n={0} and stream_name={1}".format(n,stream_name))
    if stream_name == "even":
        print_from_stream(n)
    else:
        print_from_stream(n, OddStream())
