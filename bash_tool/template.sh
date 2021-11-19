#!/bin/bash
########################################################################
# File Name: template.sh
# Author: LiuYang
# mail: liu-yang91@qq.com
# Created Time: Fri 19 Nov 2021 02:03:41 PM CST
#########################################################################

usage="$ `basename $0`  <option> \n
\n
Options:\n
-n --no-param\t\t\t\t no need parames\n
-p --have-param    <value>\t\t need parames\n
-m[value] --maybe-param[=value]\t can add parames or not\n
-h --help\t\t\t\t help message.\n
"

## handle parameters
OPTS=`getopt -o np:m::h -l no-param,have-param:,maybe-param:: -- "$@"`
if [ $? != 0 ] || [ $# -lt 2 ]; then
    echo -ne $usage;
    exit 0;
fi

eval set -- "$OPTS"
while true; do
    case $1 in
        -n|--no-param)
            echo "no param is needed";
            shift;
            continue
            ;;
        -p|--have-param)
            echo "have to set param, parame:" "$2" ; 
            shift 2;
            continue
            ;;
        -m|--maybe-param)
            case $2 in
                "")
                    echo "no param";
                    shift 2
                    ;;
                *)
                    echo "can set param, param: $2"; 
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

