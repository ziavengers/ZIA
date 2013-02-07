def replace_args(s, d):
    for k, r in d.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

TYPELIST = [l.replace('\n', '') for l in open('typelist.tpl.hpp')]

def make_typelist(n):
    if n < 0:
        raise OverflowError
    lines = make_typelist(n - 1) if n else []
    kwargs = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'templates' : ('<' + ', '.join('P%d' % i for i in range(1, n + 1)) + '>') if n else '',
        'params' : ', '.join('P%d p%d' % (i, i) for i in range(1, n + 1)),
        'params_names' : ', '.join('p%d' % i for i in range(1, n + 1)),
        'list_params' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(1, n + 1)),
        'list_params_next' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(2, n + 1))
        }
    for line in TYPELIST:
        if n or not line.endswith('// IGNORE_0'):
            lines.append(replace_args(line, kwargs))
    return lines
