import subprocess
def check(expr,result):
        out=subprocess.run(['./a.out',expr],stdout=subprocess.PIPE)
        if out.stdout.decode('ascii') !=result:
                print('{0}!={2},got {1} =>  Wrond Answer'.format(expr,result,out.stdout.decode('ascii')))
        else:
                print('{0}=={2},got {1} => Accepted'.format(expr,result,out.stdout.decode('ascii')))
check('2', '2', '2','2 nullptr')

