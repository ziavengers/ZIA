from generator import loadfile, replace_args

TYPELIST_SETTERS = loadfile('typelist_setters.tpl.hpp')

def getargs(n):
    args = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'templates' : ('< ' + ', '.join('P%d' % i for i in range(1, n + 1)) + ' >') if n else '',
        'params' : ', '.join('P%d p%d' % (i, i) for i in range(1, n + 1)),
        'params_names' : ', '.join('p%d' % i for i in range(1, n + 1)),
        'list_params' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(1, n + 1)),
        'list_params_next' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(2, n + 1)),
        'setters' : '\n'.join(
            replace_args(TYPELIST_SETTERS, {'i' : i}) for i in range(1, n + 1)
            ),
        'setters_members' : '\n'.join(
            replace_args(TYPELIST_SETTERS, {'i' : i}) for i in range(2, n + 1)
            )
        }
    return args
