#!/bin/bash
#########################################################################
# File Name: my_ssh.sh
# Author: liuyang
# mail: liuyang91@lenovo.com
# Created Time: Fri 12 Apr 2019 09:50:22 AM CST
#########################################################################

a="root@xx.xx.xx.xx"

usage="$ `basename $0`  <option> \n
                                                        \n
Options:                                                \n
-a \t\t ssh $a(login my ubuntu server)\n
-h --help\t\thelp message.          \n
"

## handle parameters
OPTS=`getopt -o abcdefgijklmnopqrstuvwxyzh -l help -- "$@"`
eval set -- "$OPTS"
while true; do
    case $1 in
        -a)
            ssh $a; exit 0;        shift; continue;;
        -h|--help)
            echo -ne $usage ; exit 0;;
        --)
            break ;;
        *)
            printf "Unkonwn option %s\n" "$1";
            break
    esac
done

if [ $# -ne 0 ]; then
    echo -ne $usage; exit 1
fi
