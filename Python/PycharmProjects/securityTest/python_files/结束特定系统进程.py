import psutil
import os
import signal


print('-'*8+'kill the process'+'-'*8)
pids = psutil.pids()
for pid in pids:
    p = psutil.Process(pid)
    process_name = p.name()
specific_process = "demo.exe"
if specific_process == process_name:
    print("kill the process:name(%s)-pid(%s)" % (process_name, pid))
    os.kill(pid, signal.SIGINT)
exit(0)