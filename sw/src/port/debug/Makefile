
#######################################
## Debug-Only Makefile
#######################################
## System

QUIET := @
ECHO  := echo
RM    := rm -f
CHMOD := chmod

CC    := gcc

#######################################
## Dirs

CWD := $(shell pwd)

SRCDIR := ${CWD}/../../
INCDIR := ${SRCDIR}/include
TESTDIR := ${SRCDIR}/../tests

#######################################
## FILE LIST

SRCS := \
    ${CWD}/main.c 

INCS := \
    -I${CWD} \
    -I${INCDIR} \
    -I${TESTDIR}

#######################################
## FLAGS

CFLAGS := -Wall -std=c99 -Werror -pedantic
LFLAGS := -lm

OUTPUT := ${CWD}/debug.x

#######################################
## TARGETS

debug: clean
	${CC} ${CFLAGS} ${LFLAGS} ${INCS} ${SRCS} -o ${OUTPUT}
	${QUIET}${CHMOD} +x ${OUTPUT}

clean:
	${QUIET}${RM} *.o *.log ${OUTPUT}

