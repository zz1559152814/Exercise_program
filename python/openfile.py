#!/usr/bin/python

import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("-a"   , action = 'store_true' , help="get in the path of dest file")
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
#print ergodic(os.getcwd())

#deal with the argument -a ,the son is a file ,and will open and edit the son ,otherwise try again 
filelist = ergodic(os.getcwd())[0]
if len(filelist) == 0:
	print 'false:',args.son ,'doesn\'t exsit'
elif len(filelist) == 1:
	print filelist[0]
	os.system('gedit ' + filelist[0])
else:
	print 'There is',len(filelist),'match,choose the one you want and you will open it'
	for i in range(len(filelist)):
		print i,':',filelist[i-1]
	forder = int(raw_input())
	while forder > len(filelist)-1:
		print 'over the boundary,please enter the order number again'
		forder = int(raw_input())
	os.system('gedit ' + filelist[forder])

