#!/usr/bin/python
# -*- coding: utf-8 -*-

#input two arguments
import argparse
import os
#import re
parser = argparse.ArgumentParser()
parser.add_argument("res" , action = 'store' , help="file name" )
parser.add_argument("realname" , action = 'store' , help="file name" )
args = parser.parse_args()

# #analyse the files'name of current directory,put the matched filename into matchname 
# allname = os.listdir(os.getcwd())
# matchname = []
# for name in allname:
# 	if re.match(re,name) = name:
# 		matchname.append(name)

# #the function split the fiename depend on re model
# def splitname(name):
print args.res
print args.realname