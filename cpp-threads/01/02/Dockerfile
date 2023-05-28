FROM debian:bullseye-slim AS build
RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    && rm -rf /var/lib/apt/lists/*

ARG PROGRAM_NAME=threads02
ARG CMAKE_VERSION=3.26.0

WORKDIR /app

RUN wget -O cmake.sh https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh && \
    chmod +x cmake.sh && \
    ./cmake.sh --skip-license --prefix=/usr/local && \
    rm cmake.sh

COPY CMakeLists.txt main.cc entrypoint.sh /app/
RUN cmake . -DPROGRAM_NAME=${PROGRAM_NAME} && cmake --build .

FROM debian:bullseye-slim
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/* \
    && useradd -m cuser

WORKDIR /app
COPY --from=build /app/${PROGRAM_NAME} /app/${PROGRAM_NAME}
COPY --from=build /app/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
USER cuser
ENTRYPOINT [ "/entrypoint.sh" ]
