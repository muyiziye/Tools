#!/usr/bin/env python
#

from os import path,sep
from argparse import ArgumentParser

# this code just for compatible python2.7 and python3.5
from distutils.log import Log
# Init log level to infor
log = Log(2)
printf = log.info

WORKDIR = path.dirname(path.abspath(__file__)) + sep

def parse_argument():
	"""
	This function just deal with the argument
	"""
	parser = ArgumentParser()
	parser.add_argument(
		"-n", "--nopar", help="Just input -n without parameter", action="store_true")
	parser.add_argument(
		"-p", "--haspar", help="You have to set parameter at the back of -p")
	arg = parser.parse_args()
	return arg


if __name__ == "__main__":
	dict_fvt = {}
	args = parse_argument()
	if args.nopar:
		printf(args.nopar)
	if args.haspar:
		printf(args.haspar)
	else:
		pass

