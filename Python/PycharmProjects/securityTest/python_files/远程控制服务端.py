import subprocess
import socket


def run_command(command):
    command = command.rstrip()
    try:
        child = subprocess.run(command, shell=True)
    except:
        print("Can not execute this command.\n")
    return child


s1 = socket.socket()
s1.bind(("127.0.0.1", 2345))
s1.listen(5)
send_str = "Disconnect!"
while True:
    connect, address = s1.accept()                      # type 'connect' is <class 'socket.socket'>
    connect.send(send_str.encode(encoding="gbk"))       # maybe the line of code could be commented.
    data = connect.recv(1024)
    data = bytes.decode(data)
    if data == 'quit':
        print("A connection from " + address[0])  # type 'address' is <class 'tuple'>    ('127.0.0.1', 50648)
        connect.close()

    else:
        print("The command is " + data)
        output = run_command(data)


# bind -> listen -> accept -> receive or send -> close
# send would be ignored...I guess...