#!/bin/sh
if [ -z "$PROGRAM_NAME" ]; then
    echo "ENV var PROGRAM_NAME isn't set. Abort!"
    exit 1
fi

./${PROGRAM_NAME}