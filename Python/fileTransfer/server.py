import socket

def main():
    ONE_CONNECTION_ONLY = (
        True
    )

    fileName = "file.txt"
    port = 63000
    sock = socket.socket()
    host = socket.gethostname()
    sock.bind((host, port))
    sock.listen(5)

    print("Server is listening ...")

    while True:
        connection, address = sock.accept()
        print(f"Got connection from {address}")
        data = connection.recv(1024)
        print(f"Server received {data}")

        with open(fileName, "rb") as fileToTransfer:
            data = fileToTransfer.read(1024)
            while data:
                connection.send(data)
                print(f"Sent {data!r}")
                data = fileToTransfer.read(1024)

        print("Done sending")
        connection.close()
        if (ONE_CONNECTION_ONLY):
            break

        sock.shutdown(1)
        sock.close()


if __name__ == "__main__":
    main()