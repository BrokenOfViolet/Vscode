import socket

while 1:
    message = input("Please input the message you want to send(press 'quit' to end the process):\n")
    handler = socket.socket()
    handler.connect(("127.0.0.1", 2345))
    if message == 'quit':
        break
    else:
        message = message.encode(encoding="gbk")
        handler.send(message)
        print(str(handler.recv(1024)))
        handler.close()

# At the first time,the primary version of the program.Program attempts to connect the sever-side
# But it just runs one time,then break the connection(handler.close())
# Then the upgrade version,I use a loop(while) to attempt keep the connection.After some attempts,some problems comes.
# After input the 'quit' in the client-side,sever-side break the process,and client-side can't end sucessfully.
# Maybe two sides must break the connection at the SAME time?I just guess it.