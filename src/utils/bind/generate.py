#!/usr/bin/env python

from storage import make_storage
from typelist import make_typelist
from traits import make_traits
from bind import make_bind

from utils import *

N = 6

from os import mkdir
try:
    mkdir('build')
except FileExistsError:
    pass

tranforms = [
    ('Storage.tpl.hpp', 'build/Storage.hpp', make_storage),
    ('Typelist.tpl.hpp', 'build/Typelist.hpp', make_typelist),
    ('Traits.tpl.hh', 'build/Traits.hh', make_traits),
    ('bind.tpl.hpp', 'build/bind.hpp', make_bind)
]
for fin, fout, getargs in tranforms:
    print('%s -> %s' % (fin, fout))
    tpl_to_file(fin, fout, getargs, N)
