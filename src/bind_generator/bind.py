def replace_args(s, d):
    for k, r in d.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

BIND = [l.replace('\n', '') for l in open('bind.tpl.hpp')]
BIND_P_TYPE = open('bind_p_type.tpl.hpp').readlines()[0].replace('\n', '')

def make_bind(n):
    if n < 0:
        raise OverflowError
    lines = make_bind(n - 1) if n else []
    kwargs = {
        'n' : n,
        'X_typenames' : (', ' + ', '.join('typename X%d' % i for i in range(1, n + 1))) if n else '',
        'Param_typenames' : (', ' + ', '.join('typename Param%d' % i for i in range(1, n + 1))) if n else '',
        'Param_templates' : ('<' + ', '.join('Param%d' % i for i in range(1, n + 1)) + '>') if n else '',
        'X_params' : ', '.join('X%d' % i for i in range(1, n + 1)),
        'Param_params' : (', ' + ', '.join('Param%d p%d' % (i, i) for i in range(1, n + 1))) if n else '',
        'Param_params_simple' : ('(' + ', '.join('p%d' % i for i in range(1, n + 1)) + ')') if n else '',
        'P_types' : '\n'.join(
            replace_args(BIND_P_TYPE, {'d' : i}) for i in range(1, n + 1)
            ),
        'P_templates' : ('<' + ', '.join('P%d' % i for i in range(1, n + 1)) + '>') if n else '',
        'X_typenames_next' : (', ' + ', '.join('typename X%d' % i for i in range(2, n + 1))) if n > 1 else '',
        'X_params_next' : ', '.join('X%d' % i for i in range(2, n + 1))
        }
    for line in BIND:
        if n or not line.endswith('// IGNORE_0'):
            lines.append(replace_args(line, kwargs))
    return lines
