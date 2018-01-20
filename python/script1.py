#!/usr/bin/python

import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("-a"   , action = 'store_true' , help="get in the path of dest file")
parser.add_argument("-o"   , action = 'store_true' , help="open the file and edit")
parser.add_argument("son" , action = 'store'      , help="file name" )
args = parser.parse_args()
filelist = []
pathlist = []

def ergodic(path):
	all_son = os.listdir(path)
	for son in all_son:
		pathname = os.path.join(path,son)
		if os.path.isfile(pathname):
			if son == args.son or pathname == args.son:
				filelist.append(pathname)
		else: 
			if son == args.son or pathname == args.son:
				pathlist.append(pathname)
			ergodic(pathname)
	return filelist,pathlist
print ergodic(os.getcwd())[1]
