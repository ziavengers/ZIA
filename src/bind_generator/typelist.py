TYPELIST = (
    'template <{typenames}>',
    'struct TypeList{n} : private Storage{n}{templates}',
    '{{',
    'typedef Storage{n}{templates} BaseClass;',
    'TypeList{n}({params}) : BaseClass({params_names}) {{}}',
    'template <typename T>',
    'T& operator[](Value<T>& v)',
    '{{',
    'return v.get();',
    '}}',
    'template <typename ReturnType, typename Caller, typename List>',
    'ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)',
    '{{',
    'return caller({list_params});',
    '}}',
    '}};',

    'template <{typenames}>',
    'struct TypeListMember{n} : private Storage{n}{templates}',
    '{{',
    'typedef Storage{n}{templates} BaseClass;',
    'TypeListMember{n}({params}) : BaseClass({params_names}) {{}}',
    'template <typename T>',
    'T& operator[](Value<T>& v)',
    '{{',
    'return v.get();',
    '}}',
    'template <typename ReturnType, typename Caller, typename List>',
    'ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)',
    '{{',
    'return (list[BaseClass::_t1].*caller)({list_params_next});',
    '}}',
    '}};',
    )

IGNORE_0 = tuple([0] + list(range(16, 32)))

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
    for i, line in enumerate(TYPELIST):
        if n or (not i in IGNORE_0):
            lines.append(line.format(**kwargs))
    return lines
