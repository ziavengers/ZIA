def getargs(n):
    args = {
        'n' : n,
        'n_prec' : n - 1,
        'typenames' : ', '.join('typename T%d' % i for i in range(1, n + 1)),
        'templates_prec' : ('< ' + ', '.join('T%d' % i for i in range(1, n)) + ' >') if n > 1 else '',
        'params' : ', '.join('T%d& t%d' % (i, i) for i in range(1, n + 1)),
        'params_prec' : ', '.join('t%d' % i for i in range(1, n))
        }
    return args
