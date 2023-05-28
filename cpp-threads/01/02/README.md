### Docker
```
docker build . -t threads02
docker run --env-file .env -it threads02
```

## Build args
```
ARG PROGRAM_NAME=threads02
ARG CMAKE_VERSION=3.26.0
```

## .env file
```
PROGRAM_NAME=threads02
MAX_THREADS=4
```