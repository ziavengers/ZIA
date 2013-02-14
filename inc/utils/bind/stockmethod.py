def getargs(n):
    args = {
        'n' : n,
        'typenames' : (', ' + ', '.join('typename P%d' % i for i in range(1, n + 1))) if n else '',
        'params' : ', '.join('P%d p%d' % (i, i) for i in range(1, n + 1)),
        'params_names' : ', '.join('p%d' % i for i in range(1, n + 1)),
        'params_types' : ', '.join('P%d' % i for i in range(1, n + 1))
        }
    return args
