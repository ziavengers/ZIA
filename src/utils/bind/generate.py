#!/usr/bin/env python

#from storage import make_storage
#from typelist import make_typelist
#from traits import make_traits
#from bind import make_bind

import sys
from utils import *

try:
    N = int(sys.argv[1])
    if N < 0:
        raise OverflowError
except:
    sys.stderr.write('Usage: %s N\n' % sys.argv[0])
    exit()

from os import mkdir
try:
    mkdir('build')
except FileExistsError:
    pass

#tranforms = [
#    ('Storage.tpl.hpp', 'build/Storage.hpp', make_storage),
#    ('Typelist.tpl.hpp', 'build/Typelist.hpp', make_typelist),
#    ('Traits.tpl.hh', 'build/Traits.hh', make_traits),
#    ('bind.tpl.hpp', 'build/bind.hpp', make_bind)
#]
transforms = [
    ('Storage.tpl.hpp', 'build/Storage.hpp', 'storage'),
    ('Typelist.tpl.hpp', 'build/Typelist.hpp', 'typelist'),
    ('Traits.tpl.hh', 'build/Traits.hh', 'traits'),
    ('bind.tpl.hpp', 'build/bind.hpp', 'bind')
]
for fin, fout, module in transforms:
    print('%s -> %s' % (fin, fout))
    tpl_to_file(fin, fout, __import__(module).getargs, N)
