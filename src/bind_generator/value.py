VALUE = (
    'template <typename T>',
    'class Value',
    '{',
    'public:',
    'Value(T& t) : _t(t) {}',
    'T& get() { return _t; }',
    'const T& get() const { return _t; }',
    'protected:',
    'T _t;',
    '};',
    'template <typename T>',
    'class GetType',
    '{',
    'public:',
    'typedef Value<T> Type;',
    '};',
    'template <typename T>',
    'struct TypeTraits',
    '{};'
    )

def make_value(n = 0):
    return list(VALUE)
