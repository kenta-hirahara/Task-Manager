FROM ubuntu:latest

WORKDIR /app

COPY build/task-manager /app/task-manager

CMD ["./task-manager"]
