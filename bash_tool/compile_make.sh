#!/bin/bash
########################################################################
# File Name: template.sh
# Author: LiuYang
# mail: liu-yang91@qq.com
# Created Time: Fri 19 Nov 2021 02:03:41 PM CST
#########################################################################

# define some environment value
BUILD_MODE=release
ENABLE_GCOV=False
ENABLE_ASAN=False
ONLY_PRINT=False

COMPILE_FLAGS=" -Wall -Werror "

MAKE_CMD="make"

SRC_PATH=`pwd`/src
OUTPUT_PATH="./compile_output_${BUILD_MODE}"


# hand the options
usage="$ `basename $0`  <option> \n
\n
Options:\n
-d --debug\t\t\t\t Set debug mode, default is release.\n
-g --gcov\t\t\t\t Compile with gcov's options. Alway used in debug mode.\n
-a --asan\t\t\t\t Compile with asan's options. Alway used in debug mode.\n
-p --print\t\t\t\t Just print the finally Make command.\n
-o --output <value>\t\t\t set the build output path\n
-t[only] --unittest[=only]\t\t compile unittest, only means just compile unittest\n
-h --help\t\t\t\t help message.\n
"

## handle parameters
OPTS=`getopt -o dgao:pt::h -l debug,gcov,asan,output:,print,unittest:: -- "$@"`
if [ $? != 0 ]; then
    echo -ne $usage;
    exit 1
fi

eval set -- "$OPTS"
while true; do
    case $1 in
        -d|--debug)
			BUILD_MODE=debug
            shift;
            continue
            ;;
        -g|--gcov)
			ENABLE_GCOV=True
            shift;
            continue
            ;;
        -a|--asan)
			ENABLE_ASAN=True
            shift;
            continue
            ;;
        -o|--output)
            echo "Set output path: $2" ; 
			OUTPUT_PATH="$2"
            shift 2;
            continue
            ;;
        -p|--print)
			ONLY_PRINT=True
            shift;
            continue
            ;;
        -t|--unittest)
            case $2 in
                "")
                    echo "compile with unittest";
                    shift 2
                    ;;
                *)
                    echo "can set param, param: $2"; 
					if [ x$2 == x"only" ]; then
						echo "only compile unittest"
					else
						echo "compile with unittest"
					fi
                    shift 2
                    ;;
            esac
            ;;
        -h|--help)
            echo -ne $usage;
             exit 0;;
        --)
            shift;
            break;;
        *)
            printf "Unkonwn option %s\n" "$1";
            break
    esac
done

if [ x${BUILD_MODE} == x"release" ];then
	COMPILE_FLAGS=" ${COMPILE_FLAGS} -O2 "
else
	COMPILE_FLAGS=" ${COMPILE_FLAGS} -O0 -g "
fi

if [ x${ENABLE_GCOV} == x"True" ];then
	COMPILE_FLAGS=" ${COMPILE_FLAGS} -fprofile-arcs -ftest-coverage "
fi

if [ x${ENABLE_ASAN} == x"True" ];then
	COMPILE_FLAGS=" ${COMPILE_FLAGS} -fsanitize=address "
fi

MAKE_CMD="${MAKE_CMD} MY_CXXFLAGS=\"${COMPILE_FLAGS}\" -j8"


if [ x${ONLY_PRINT} == x"True" ];then
	echo ${MAKE_CMD}
else
	echo ${MAKE_CMD} | bash 
fi
	
