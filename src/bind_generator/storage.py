def replace_args(s, d):
    for k, r in d.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

STORAGE = [l.replace('\n', '') for l in open('storage.tpl.hpp')]

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
    for line in STORAGE:
        if n or not line.endswith('// IGNORE_0'):
            lines.append(replace_args(line, kwargs))
    return lines
