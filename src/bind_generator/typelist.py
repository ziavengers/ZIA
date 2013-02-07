def make_typelist(n):
    kwargs = {
        'n' : n,
        'typenames' : ', '.join('typename P%d' % i for i in range(1, n + 1)),
        'templates' : ('<' + ', '.join('P%d' % i for i in range(1, n + 1)) + '>') if n else '',
        'params' : ', '.join('P%d p%d' % (i, i) for i in range(1, n + 1)),
        'params_names' : ', '.join('p%d' % i for i in range(1, n + 1)),
        'list_params' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(1, n + 1)),
        'list_params_next' : ',\n'.join('list[BaseClass::_t%d]' % i for i in range(2, n + 1))
        }
    return kwargs
