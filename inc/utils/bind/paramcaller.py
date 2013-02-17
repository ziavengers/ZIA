from generator import loadfile, replace_args

PARAMCALLER_SETTERS = loadfile('paramcaller_setters.tpl.hpp')

def getargs(n):
    args = {
        'setters' : '\n'.join(
            replace_args(PARAMCALLER_SETTERS, {'i' : i}) for i in range(1, n + 1)
            )
        }
    return args
