def replace_args(s, d):
    for k, r in d.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

TRAITS_TYPE_PARAM = open('traits_type_param.tpl.hpp').readlines()[0].replace('\n', '')

def make_traits(n):
    kwargs = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'type_params' : '\n'.join(
            replace_args(TRAITS_TYPE_PARAM, {'i' : i}) for i in range(1, n + 1)
            ),
        'templates_type_params' : ('<' + ', '.join('Type_Param%d' % i for i in range(1, n + 1)) + '>') if n else ''
        }
    return kwargs
