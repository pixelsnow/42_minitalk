# Minitalk

✅ Passed with **125**/100

My version of **minitalk** School 42 project @ [Hive Helsinki](https://www.hive.fi/en/)

A small data exchange (client-server) program using UNIX signals.

## Task description

You must create a communication program in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
    - The server PID.
    - The string to send.
- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
- Your server should be able to receive strings from several clients in a row without needing to restart.
- The communication between your client and your server has to be done only using UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.

## Bonus part

- The server acknowledges every message received by sending back a signal to the
client.
- Unicode characters support!

## How to run

- `cd` into the directory.
- `make` to compile.
- `./server` to run server. Server will display its' process id, copy it!
- Client takes two arguments: server process id and a string to send. Run it in a second terminal like so: `./client_bonus {process_id} {your_message}`.
Example with process id 13629: `./client 13629 "Message to send 🦕"`

## How to run bonus

- `cd` into the directory
- `make bonus` to compile
- `./server_bonus` to run server.
- `./client_bonus {process_id} {your_message}` to send your message to server.
- This time server will send a confirmation to the client after the message was received. Very wow!
