CALLER = (
    'template <typename ReturnType>',
    'class ICaller',
    '{',
    'public:',
    'virtual ~ICaller() {}',
    'virtual ReturnType operator()() = 0;',
    '};',
    'template <typename ReturnType, typename Callable, typename List>'
    'class Caller : public ICaller<ReturnType>',
    '{',
    'public:',
    'Caller(Callable callable, List list) : _callable(callable), _list(list) {}',
    'ReturnType operator()()',
    '{',
    'return _list(TypeTraits<ReturnType>(), _callable, _list);',
    '}',
    'protected:',
    'Callable _callable;',
    'List _list;',
    '};'
    )

def make_caller(n = 0):
    return list(CALLER)
