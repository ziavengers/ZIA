#!/usr/bin/env python

from storage import make_storage
from typelist import make_typelist
from traits import make_traits
from bind import make_bind

def replace_args(s, args):
    for k, r in args.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

def next_line(tpl, n, getargs):
    if n < 0:
        raise OverflowError
    with open(tpl, 'r') as f:
        lines = [l for l in f]
        for i in range(n + 1):
            for line in lines:
                if i or not line.replace('\n', '').endswith('// IGNORE_0'):
                    yield replace_args(line, getargs(i))

def name_to_define(name):
    return ''.join(c if c.isalnum() else '_' for c in name.upper()) + '_'

def tpl_to_file(tpl, filename, n, getargs):
    with open(filename, 'w') as f:
        define = name_to_define(filename)
        f.write('#ifndef %s\n' % define)
        f.write('#define %s\n' % define)
        for line in next_line(tpl, n, getargs):
            f.write(line)
        f.write('#endif\n')

def tpl_to_str(tpl, n, getargs):
    return ''.join(next_line(tpl, n, getargs))

N = 6

from os import mkdir
try:
    mkdir('build')
except FileExistsError:
    pass

tranforms = [
    ('storage.tpl.hpp', 'build/storage.hpp', make_storage),
    ('typelist.tpl.hpp', 'build/typelist.hpp', make_typelist),
    ('traits.tpl.hh', 'build/traits.hh', make_traits),
    ('bind.tpl.hpp', 'build/bind.hpp', make_bind)
]
for fin, fout, getargs in tranforms:
    print('%s -> %s' % (fin, fout))
    tpl_to_file(fin, fout, N, getargs)
