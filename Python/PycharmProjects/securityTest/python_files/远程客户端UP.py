import socket


client = socket.socket()
client.connect(("127.0.0.1", 9998))

while True:
    cmd = input("(quit退出>>".strip())
    if len(cmd) == 0:
        continue
    if cmd == 'quit':
        break
    client.send(cmd.encode())
    cmd_res = client.recv(1024)             # what this code line mean?
    print(cmd_res.decode())

client.close()