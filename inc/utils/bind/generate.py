#!/usr/bin/env python

import sys
from utils import *

try:
    N = int(sys.argv[1])
    if N < 0:
        raise OverflowError
except:
    sys.stderr.write('Usage: %s N\n' % sys.argv[0])
    exit()

from os import mkdir, getcwd, path
try:
    mkdir('build')
except FileExistsError:
    pass
transforms = [
    ('Storage.tpl.hpp', 'build/Storage.hpp', 'storage'),
    ('Typelist.tpl.hpp', 'build/Typelist.hpp', 'typelist'),
    ('Traits.tpl.hh', 'build/Traits.hh', 'traits'),
    ('ParamCaller.tpl.hpp', 'build/ParamCaller.hpp', 'paramcaller'),
    ('StockMethod.tpl.hpp', 'build/StockMethod.hpp', 'stockmethod'),
    ('bind.tpl.hpp', 'build/bind.hpp', 'bind')
]
print('Generation bind for %d parameters' % N)
for fin, fout, module in transforms:
    print('%s -> %s' % (path.join(getcwd(), fin), path.join(getcwd(), fout)))
    tpl_to_file(fin, fout, __import__(module).getargs, N)
