#!/usr/bin/env python

from value import make_value
from storage import make_storage
from typelist import make_typelist
from traits import make_traits
from caller import make_caller
from bind import make_bind

N = 6

lines = []
funcs = [make_value, make_storage, make_typelist, make_traits, make_caller, make_bind]
for f in funcs:
    lines += f(N)
print('\n'.join(lines))
