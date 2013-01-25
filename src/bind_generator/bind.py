BIND = (
    'template <typename ReturnType{X_typenames}{Param_typenames}>',
    'Caller<ReturnType, ReturnType(*)({X_params}), typename Traits{n}{Param_templates}::Type>',
    'bind(ReturnType(*f)({X_params}){Param_params})',
    '{{',
    '{P_types}',
    'typedef TypeList{n}{P_templates} ListType;',
    'ListType l{Param_params_simple};',
    'return Caller<ReturnType, ReturnType(*)({X_params}), ListType >(f, l);',
    '}}',
    
    'template <typename ReturnType{Param_typenames}, typename Object>',
    'Caller<ReturnType, Object, typename Traits{n}{Param_templates}::Type>',
    'bind(Object& o{Param_params})',
    '{{',
    '{P_types}',
    'typedef TypeList{n}{P_templates} ListType;',
    'ListType l{Param_params_simple};',
    'return Caller<ReturnType, Object, ListType >(o, l);',
    '}}'
    )

BIND_P_TYPE = 'typedef typename GetType<Param%d>::Type P%d;'

IGNORE_0 = (4, 13)

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
            BIND_P_TYPE % (i, i) for i in range(1, n + 1)
            ),
        'P_templates' : ('<' + ', '.join('P%d' % i for i in range(1, n + 1)) + '>') if n else ''
        }
    for i, line in enumerate(BIND):
        if n or (not i in IGNORE_0):
            lines.append(line.format(**kwargs))
    return lines
