#!/usr/bin/env python

import sys

try:
    N = int(sys.argv[1])
    ZIA_PATH = sys.argv[2]
    if N < 0:
        raise OverflowError
except:
    sys.stderr.write('Usage: %s N ZIA_PATH\n' % sys.argv[0])
    exit()

from os import mkdir, getcwd, path

sys.path.append(path.join(ZIA_PATH, 'src/utils/'))
from generator import *

try:
    mkdir('build')
except FileExistsError:
    pass

def getargs_emit(n):
    args = {
        'n' : n,
        'typenames' : ', '.join('typename T%d' % i for i in range(1, n + 1)),
        'templates' : ('< ' + ', '.join('T%d' % i for i in range(1, n + 1)) + ' >') if n else '',
        'params' : (', ' + ', '.join('T%d t%d' % (i, i) for i in range(1, n + 1))) if n else '',
        'params_names' : (', ' + ', '.join('t%d' % i for i in range(1, n + 1))) if n else '',
        'setparams' : '\n'.join('caller->set%d(t%d);' % (i, i) for i in range(1, n + 1)),
        'get_type_names' : ' + std::string(", ") + '.join('std::string(getTypeName(T%d))' % i for i in range(1, n + 1)) if n else '""'
        }
    return args

transforms = [
    ('emit.tpl.hpp', 'build/emit.hpp', getargs_emit)
]

print('Generation Object::emit for %d parameters' % N)
for fin, fout, getargs in transforms:
    print('%s -> %s' % (path.join(getcwd(), fin), path.join(getcwd(), fout)))
    tpl_to_file(fin, fout, getargs, N)
