TRAITS = (
    'template <{typenames}>',
    'struct Traits{n}',
    '{{',
    '{type_params}',
    'typedef TypeList{n}{templates_type_params} Type;',
    '}};'
    )

TRAITS_TYPE_PARAM = 'typedef typename GetType<P%d>::Type Type_Param%d;'

IGNORE_0 = (0, 3)

def make_traits(n):
    if n < 0:
        raise OverflowError
    lines = make_traits(n - 1) if n else []
    kwargs = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'type_params' : '\n'.join(
            TRAITS_TYPE_PARAM % (i, i) for i in range(1, n + 1)
            ),
        'templates_type_params' : ('<' + ', '.join('Type_Param%d' % i for i in range(1, n + 1)) + '>') if n else ''
        }
    for i, line in enumerate(TRAITS):
        if n or (not i in IGNORE_0):
            lines.append(line.format(**kwargs))
    return lines
