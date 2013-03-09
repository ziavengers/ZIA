def replace_args(s, args):
    for k, r in args.items():
        s = s.replace('@%s@' % k, '%s' % r)
    return s

def next_line(tpl, getargs, n):
    with open(tpl, 'r') as f:
        lines = [l for l in f]
        r = range(n + 1)
        if lines[0].startswith('// JUST_ONCE'):
            lines = lines[1:]
            r = range(n, n + 1)
        for i in r:
            for line in lines:
                if i or not line.replace('\n', '').endswith('// IGNORE_0'):
                    yield replace_args(line, getargs(i))

def name_to_define(name):
    return ''.join(c if c.isalnum() else '_' for c in name.upper()) + '_'

def tpl_to_file(tpl, filename, getargs, n, prefix = '', namespaces = ()):
    with open(filename, 'w') as f:
        define = name_to_define(filename)
        f.write('#ifndef %s%s\n' % (prefix, define))
        f.write('#define %s%s\n' % (prefix, define))
        for namespace in namespaces:
            f.write('namespace %s {\n' % namespace)
        for line in next_line(tpl, getargs, n):
            f.write(line)
        for _ in namespaces:
            f.write('}\n')
        f.write('#endif\n')

def tpl_to_str(tpl, getargs, n = 0):
    return ''.join(next_line(tpl, getargs, n))

def loadfile(filename):
    with open(filename, 'r') as f:
        return ''.join(l for l in f)
    return ''
