def replace_args(s, d):
    for k, r in d.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

TRAITS = [l.replace('\n', '') for l in open('traits.tpl.hh')]
TRAITS_TYPE_PARAM = open('traits_type_param.tpl.hpp').readlines()[0].replace('\n', '')

def make_traits(n):
    if n < 0:
        raise OverflowError
    lines = make_traits(n - 1) if n else []
    kwargs = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'type_params' : '\n'.join(
            replace_args(TRAITS_TYPE_PARAM, {'d' : i}) for i in range(1, n + 1)
            ),
        'templates_type_params' : ('<' + ', '.join('Type_Param%d' % i for i in range(1, n + 1)) + '>') if n else ''
        }
    for line in TRAITS:
        if n or not line.endswith('// IGNORE_0'):
            lines.append(replace_args(line, kwargs))
    return lines
