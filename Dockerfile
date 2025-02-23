FROM ubuntu:latest

WORKDIR /app

COPY build/test/exec_taskmanager /app/exec_taskmanager

CMD ["./exec_taskmanager"]
