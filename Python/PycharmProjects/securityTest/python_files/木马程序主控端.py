import socketserver


class MyTCPHandler(socketserver.BaseRequestHandler):
    def handle(self):
        try:
            while True:
                self.data = self.request.recv(1024)
                cmd = input("(quit退出>>").rstrip()
                if len(cmd) == 0:
                    continue
                if cmd == 'quit':
                    break
                if not self.data:
                    print("connection lost.")
                    break
                self.request.sendall(cmd.encode())
        except Exception:
            print(self.client_address, "connection lost")
        finally:
            self.request.close()

    def setup(self):
        print("before handle", self.client_address)

    def finish(self):
        print("finish run after handle.")


if __name__ == '__main__':
    server = socketserver.TCPServer(("127.0.0.1", 9996), MyTCPHandler)
    server.serve_forever()