# Minitalk

![Language: C](https://img.shields.io/badge/language-C-blue.svg) 
![License: MIT](https://img.shields.io/badge/license-MIT-green.svg) 
![Status: Active](https://img.shields.io/badge/status-active-brightgreen.svg) 
![Contributions: Welcome](https://img.shields.io/badge/contributions-welcome-orange.svg)

The concept of this project is to create a program that allows two processes to communicate with each other using only signals (SIGUSR1 and SIGUSR2).<br>

## 📋 About the Project
The goal is to send messages from one process (Client) to another (Server). Since signals are the only permitted form of communication, the message is converted into bits, sent signal by signal, and reconstructed by the server.<br>

- ***Challenge***: To ensure that no signal is lost and that communication is fast and stable.<br>
- ***Signs Used:***<br>
    - SIGUSR1: Represents bit 0.
    - SIGUSR2: Represents bit 1.
 
## 🛠️ How it Works
1. The server starts and prints its PID (Process ID).

2. The client receives the server's PID and the string it wants to send.

3. The client converts each character into 8 bits and sends the corresponding signal for each bit.

4. The server receives the signals, reconstructs the bytes, and prints the final message.

## 🚀 How to Use

### 1. Compilation
Use the ```Makefile``` to compile the project:
```c
make
```
### 2. Execution
First, start the server in a terminal:
```c
./server
```
The server will display something like: ```PID: 17698```
Then, on a second terminal, send a message using the displayed PID:
```c
./client 17698 "Olá, este é o meu Minitalk! 🚀"
```

## 🤝 Contributing

To contribute, follow these steps:

1. Fork the project  
2. Create a branch (`git checkout -b feature-name`)  
3. Commit your changes (`git commit -m "new feature"`)  
4. Push the branch (`git push origin feature-name`)  
5. Open a Pull Request 🚀  

