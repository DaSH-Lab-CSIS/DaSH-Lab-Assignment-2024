# DevelopmentAssignment

## General Instructions

Refer to the shared Google Document for all instructions regarding the assignment

## Formats for Input and Output

### Level 1

#### INPUTS: [input.txt](input.txt) is a text file containing one prompt on each line

#### OUTPUTS : Your script(s) should output a json file titled "output.json" with the following format

The file should contain a JSON array of JSON Objects.

The format of the JSON Objects is as follows:

- "Prompt" which stores the original prompt sent by the client.

- "Message" which stores the response string from the API.

- "TimeSent" which stores the Time that the prompt was originally sent out by the client as a UNIX Timestamp

- "TimeRecvd" which stores the Time that the response was received by the client as a UNIX Timestamp

- "Source" which specifies the source of the response, such as Gemma, Grok or ChatGPT etc.  

An example is given in [output.json](output.json)

### Level 2

#### INPUTS: [input.txt](input.txt) is a text file containing one prompt on each line. You may split the prompts across multiple clients as you see fit.

#### OUTPUTS: Each client should output a json file that may be titled "output.json". You are free to differentiate the output files of each client anyway you see fit. 

Follow the same format as Level 1 but with the following changes.

- Add a "ClientID" key to each JSON object.

- The server sends a prompt-response pair to each client. If the client receives a prompt-response that it did not send to the server, then set the value of the "Source" key in your JSON object to "user".
