import socketserver
import subprocess


class MyTCPHandler(socketserver.BaseRequestHandler):
    def handle(self):
        try:
            while True:
                self.data = self.request.recv(1024)
                print(" {} send:".format(self.client_address), self.data)
                command = self.data.decode()
                command = command.rstrip()
                child = subprocess.run(command, shell=True)
                if not self.data:
                    print("connection lost")
                    break
                self.request.sendall(self.data.upper())
        except Exception:
            print(self.client_address, "disconnect.")
        finally:
            self.request.close()

    def setup(self):
        print("before handle,connection establishment:", self.client_address)

    def finish(self):
        print("finish run after handler.")


if __name__ == '__main__':
    server = socketserver.TCPServer(("127.0.0.1", 9998), MyTCPHandler)

server.serve_forever()


# This program