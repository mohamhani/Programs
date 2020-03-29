import socket

def main():

    s = socket.socket()
    print("Socket has been successfully created.")

    port = 7500

    s.connect(('127.0.0.1', port))

    print(s.recv(1024))

    s.close()

if __name__ == "__main__":
    main()