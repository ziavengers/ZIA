from generator import loadfile, replace_args

BIND_P_TYPE = loadfile('bind_p_type.tpl.hpp')

def getargs(n):
    args = {
        'n' : n,
        'X_typenames' : (', ' + ', '.join('typename X%d' % i for i in range(1, n + 1))) if n else '',
        'Param_typenames' : (', ' + ', '.join('typename Param%d' % i for i in range(1, n + 1))) if n else '',
        'Param_templates' : ('< ' + ', '.join('Param%d' % i for i in range(1, n + 1)) + ' >') if n else '',
        'X_params' : ', '.join('X%d' % i for i in range(1, n + 1)),
        'X_params_' : (', ' + ', '.join('X%d' % i for i in range(1, n + 1))) if n else '',
        'Param_params' : (', ' + ', '.join('Param%d p%d' % (i, i) for i in range(1, n + 1))) if n else '',
        'Param_params_simple' : ('(' + ', '.join('p%d' % i for i in range(1, n + 1)) + ')') if n else '',
        'P_types' : '\n'.join(
            replace_args(BIND_P_TYPE, {'i' : i}) for i in range(1, n + 1)
            ),
        'P_templates' : ('< ' + ', '.join('P%d' % i for i in range(1, n + 1)) + ' >') if n else '',
        'get_Param_type_names' : ' + std::string(", ") + '.join('std::string(getTypeName(Param%d))' % i for i in range(1, n + 1)) if n else '""'
        }
    return args
