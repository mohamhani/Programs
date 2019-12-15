import socket

def main():

    sock = socket.socket() # Create a socket object
    host = socket.gethostname()
    port = 63000

    sock.connect((host, port))
    sock.send(b"Hi server!")

    with open("received.txt", "wb") as outputFile:
        print("File opened")
        print("Receiving ...")
        while True:
            data = sock.recv(1024)
            print(f"data={data}")
            if not data:
                break
            outputFile.write(data)

    print("Successfully got the file")
    sock.close()
    print("Connection closed")

if __name__ == "__main__":
    main()