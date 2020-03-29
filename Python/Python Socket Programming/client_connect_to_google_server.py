import socket
import sys

def main():

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Socket has been created.")
    except socket.error as err:
        print("Socket was not created due to the following error: " + err)

    port = 80 #default port

    try:
        host = socket.gethostbyname("www.google.com")
    except:
        print("Could not connect to the desired server")
        sys.exit()

    s.connect((host, port))
    print("The socket has been connected to the server on port " + host)

if __name__ == "__main__":
    main()



