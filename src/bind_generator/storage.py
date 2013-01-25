# Lines of "struct StorageX"
STORAGE = (
    'template <{typenames}>',
    'struct Storage{n}',
    ': public Storage{n_prec}{templates_prec}',
    '{{',
    'Storage{n}({params})',
    ': Storage{n_prec}{templates_prec}({params_prec}), _t{n}(t{n})',
    '{{}}',
    'T{n} _t{n};',
    '}};'
    )

# Lines to ignore for Storage0
IGNORE_0 = (0, 2, 5, 7)

def make_storage(n):
    if n < 0:
        raise OverflowError
    lines = make_storage(n - 1) if n else []
    kwargs = {
        'n' : n,
        'n_prec' : n - 1,
        'typenames' : ', '.join('typename T%d' % i for i in range(1, n + 1)),
        'templates_prec' : ('<' + ', '.join('T%d' % i for i in range(1, n)) + '>') if n > 1 else '',
        'params' : ', '.join('T%d& t%d' % (i, i) for i in range(1, n + 1)),
        'params_prec' : ', '.join('t%d' % i for i in range(1, n))
        }
    for i, line in enumerate(STORAGE):
        if n or (not i in IGNORE_0):
            lines.append(line.format(**kwargs))
    return lines
