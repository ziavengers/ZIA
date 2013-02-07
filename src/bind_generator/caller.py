def make_caller(n = 0):
    with open('caller.hpp') as f:
        return [l.replace('\n', '') for l in f]
    return []
