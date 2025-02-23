FROM ubuntu:latest

WORKDIR /app

COPY build/test/task-manager /app/task-manager

CMD ["./task-manager"]
