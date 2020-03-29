import socket
import sys

def main():

    s = socket.socket()
    print("Socket has been successfully created.")

    port = 7500

    s.bind(('', port))
    print("Socket has been binded to " + str(port))

    s.listen(6)
    print("Socket is now listening")

    while True:

        # Establish a connection with the client
        sock, client_address = s.accept()
        print("Connected to " + str(client_address))

        # Send a message to the client
        sock.send(bytes("Thank you for connecting", "utf-8"))

        # Close the current connection with the client
        sock.close()

        # To exit the system, if you want you can take out this line. In order to maintain the connection indefinetly 
        sys.exit()

if __name__ == "__main__":
    main()