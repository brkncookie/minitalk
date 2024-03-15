# minitalk

The minitalk project involves creating two programs, a server, and a client, to communicate with each other using Linux process signals. This project explores the concept of interprocess communication (IPC) and demonstrates how to use process signals (specifically, SIGUSR1 and SIGUSR2) for communication between processes.

## Description

### Server and Client Communication:
- The server program must be started first. Upon launch, it prints its PID (Process ID).
- The client program takes two parameters:
  - The PID of the server.
  - The string to send to the server.
- The client sends the string passed as a parameter to the server using process signals.
- Upon receiving the string, the server prints it.

### Performance Expectations:
- The server should display the received string quickly. If it takes too long, it's considered inefficient.
- The server should handle receiving strings from multiple clients in succession without needing to restart.

### Key Concepts Learned:
- Interprocess Communication (IPC): Understanding how processes can communicate with each other, share data, and synchronize their actions.
- Process Signals: Using predefined Linux signals to facilitate communication and coordination between processes.

## Getting Started

To get started with the minitalk project, follow these steps:

1. **Clone the Repository:**

   ```bash
       $ git clone https://github.com/brkncookie/minitalk.git
   ```
2. **Compile the Server and Client Programs:**
   
   ```bash
     $ cd minitalk
     $ make
   ```
3. **Launch the Server:**
  
    ```bash
      $ ./server
      Server PID: <pid>
    ```
4. **Run the Client:**
    
    ```bash
      $ ./client <server_pid> "Hello, server!"
    ```
## Resources

- [Linux Signals](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Interprocess Communication in Unix](https://www.cs.cf.ac.uk/Dave/C/node27.html)
