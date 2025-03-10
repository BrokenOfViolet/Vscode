import psutil


print('-'*7+'show all process information'+'-'*7)
pids = psutil.pids()
for pid in pids:
    process = psutil.Process(pid)
    process_name = process.name()
    print("Process name is %s, pid is %s" % (process_name, pid))

print('-'*20)