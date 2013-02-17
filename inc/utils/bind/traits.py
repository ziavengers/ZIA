from generator import loadfile, replace_args

TRAITS_TYPE_PARAM = loadfile('traits_type_param.tpl.hpp')

def getargs(n):
    args = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'type_params' : '\n'.join(
            replace_args(TRAITS_TYPE_PARAM, {'i' : i}) for i in range(1, n + 1)
            ),
        'templates_type_params' : ('< ' + ', '.join('Type_Param%d' % i for i in range(1, n + 1)) + ' >') if n else ''
        }
    return args
